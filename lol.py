import os
import subprocess
import json
import requests

reqid = os.environ['TRAVIS_PULL_REQUEST']
js = requests.get('https://api.github.com/repos/valera5505/SPbU/pulls/' + reqid + '/files').json()

for fl in js:
    if fl['status'] == 'removed':
        continue
    if not fl['filename'].endswith('.cpp'):
        continue
    print(fl['filename'] + ' is compiling')
    process = subprocess.Popen(['g++', '-o', fl['filename'] + '.fuck',fl['filename']], stdout=subprocess.PIPE)
    process.wait()
    process = subprocess.Popen(['./' + fl['filename'] + '.fuck'], stdout=subprocess.PIPE)
    process.wait()
	
