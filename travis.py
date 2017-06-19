import os
import subprocess
import json
import requests

reqid = os.environ['TRAVIS_PULL_REQUEST']
js = requests.get('https://api.github.com/repos/valera5505/SPbU/pulls/' + reqid + '/files').json()

for i in range(len(js)):
    if js[i]['status'] == 'removed':
        continue
    if not js[i]['filename'].endswith('.cpp'):
        continue
    print(js[i]['filename'] + ' is compiling')

    if not os.path.exists(os.path.dirname(js[i]['filename']) + '/stdafx.h'):
        f = open(os.path.dirname(js[i]['filename']) + '/stdafx.h', 'a+')
        f.write('#include <stdio.h>')
        f.close();
    
    process = subprocess.Popen(['g++-6', '-o', js[i]['filename'] + '.' + str(i), js[i]['filename'], '-std=c++14', '-pthread'], stdout=subprocess.PIPE)
    process.wait()

    if not os.path.exists(js[i]['filename'] + '.' + str(i)):
        exit(1)
    else:
        print("success");
    
