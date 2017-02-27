import os
import subprocess
import json
import requests

reqid = os.environ['TRAVIS_PULL_REQUEST']
js = requests.get('https://api.github.com/repos/valera5505/SPbU/pulls/' + reqid + '/files').json()

for i in range(len(js)):
    if js[i]['status'] == 'removed':
        continue
    if not js[i]['filename'].endswith('.java'):
        continue
    print(js[i]['filename'] + ' is compiling')
	
    process = subprocess.Popen(['javac', js[i]['filename']], stdout=subprocess.PIPE)
    process.wait()

    if not os.path.exists(js[i]['filename'] + '.class'):
        print("error");
    else:
        print("success");
    
