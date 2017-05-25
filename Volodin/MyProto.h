#include <iomanip>
#include <algorithm>
namespace protos {
	using namespace std;
	const vector <string> typeName = {
		"Authorize" ,
		"AuthAnswer",
		"Message",
	};
	struct MyProto {
		string type;
		string sendername;
		string gettername;
		int messageSize;
		string message;
		string name;
		bool authAnswer;
		bool aa;

		MyProto(const char* c) {
			stringstream s;
			s << c;
			s >> type;
			if (type == "Message")
				ptosMessage(s);
			if (type == "Authorize")
				ptosAuthorize(s);
			if (type == "AuthAnswer")
				ptosAuthAnswer(s);
		}
		int getBytes(char* req) {
			string s = type + " ";
			if (type == "Message")
				s += stopMessage();
			if (type == "Authorize")
				s += stopAuthorize();
			if (type == "AuthAnswer")
				s += stopAuthAnswer();
			strcpy(req, s.c_str());
			return s.length() + 1;
		}
		void out() {
			if (type == "Message")
				cout << "From: " << sendername << "\nMessage: " << message << endl;
		}
		MyProto(string sendn, string getn, string msg) :type("Message"), sendername(sendn), gettername(getn), message(msg), messageSize(msg.length()) {}
		MyProto(string name) : type("Authorize"), name(name) {}
		MyProto(bool authAnswer) : type("AuthAnswer"), authAnswer(authAnswer) {}
	private:
		const string CONGRATULATION = "Yo, I congratulate you and wish you the best"
			" luck, the best code, big money and whatever you want. Happy New 2017 Year!!!";
		void ptosMessage(stringstream& s) {
			s >> sendername >> gettername >> messageSize;
			message = cinText(s, messageSize);	
		}
		string stopMessage() {
			string str = message;
			std::transform(message.begin(), message.end(), str.begin(), ::toupper);
			if (str == "CONGRATULATION")
				message = CONGRATULATION;
			return sendername + " " + gettername + " " + to_string(message.size()) + " " + message;
		}
		void ptosAuthorize(stringstream& s) {
			s >> name;
		}
		string stopAuthorize() {
			return name;
		}
		void ptosAuthAnswer(stringstream& s) {
			s >> authAnswer;
		}
		string stopAuthAnswer() {
			return to_string(authAnswer);
		}
	private:
		string cinText(stringstream& s, int textSize) {
			char cc; s >> noskipws >> cc;
			char *t = new char[textSize + 2];
			s.get(t, textSize + 1);
			string text = t;
			delete t;
			return text;
		}
	};
}