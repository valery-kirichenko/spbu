package DateBase;

public class Credit {
    int id;
    double sum,nSum,paySum,percent;
    String date;

    public Credit() {
        id = 0;
        sum = 0;
        nSum = 0;
        paySum = 0;
        percent = 0;
        date = "";
    }

    public Credit(int nid,double nsum,double nnSum,double npaySum,double npercent,String ndate) {
        id = nid;
        sum = nsum;
        nSum = nnSum;
        paySum = npaySum;
        percent = npercent;
        date = ndate;
    }

    public int getID(){
        return id;
    }

    public double getSum(){
        return sum;
    }

    public double getnSum(){
        return nSum;
    }

    public double getPaySum(){
        return paySum;
    }

    public double getPercent(){
        return percent;
    }

    public String getDate(){
        return date;
    }

    public void printInf(){
        System.out.println(String.valueOf(id)+' '+String.valueOf(sum)+' '+String.valueOf(percent)+' '+String.valueOf(nSum)+' '+String.valueOf(paySum)+' '+date);
    }
}
