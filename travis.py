import os
import subprocess
import json
import requests

reqid = os.environ['TRAVIS_PULL_REQUEST']
js = requests.get('https://api.github.com/repos/valera5505/SPbU/pulls/' + reqid + '/files').json()

for i in range(0, len(js)-1):
    if fl[i]['status'] == 'removed':
        continue
    if not fl[i]['filename'].endswith('.cpp'):
        continue
    print(fl[i]['filename'] + ' is compiling')
    process = subprocess.Popen(['g++', '-o', fl[i]['filename'] + '.' + i,fl[i]['filename']], stdout=subprocess.PIPE)
    process.wait()

    if not os.path.exists(fl[i]['filename'] + '.' + i):
        exit(1)
    
