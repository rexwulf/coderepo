import os
import commands

dir = '/Users/rex/Downloads/eJOI_Day_2_tests/game_tests/'
os.chdir(dir)
files = os.listdir('.')
files.sort()
print(files)
count = 0
for f in files:
    temp = f.split('.')
    if temp[len(temp)-1] == "sol":
        continue
    res = commands.getstatusoutput('cd "/Users/rex/Desktop/ /" && g++ -std=c++11 main.cpp -o main && "/Users/rex/Desktop/ /"main < '+ dir + f)
    print(dir+f)
    with open(f[:f.rfind('.')]+'.sol') as g:
        ans = g.read().split('\n')
        #ans = int(ans)
        res = res[1].split('\n')
        flag = 1
        for i in range(len(ans)-1):
            if int(ans[i])!=int(res[i]):
                flag = 0
                break
        

        if flag:
            print("passed: "+f)
            count+=1
        else:
            print("failed: "+f)
            print("found:")
            print(res)
            print("ans:")
            print(ans)
        print('\n')
print("\nTOTAL TESTCASES PASSED ("+str(count)+"\\"+str(len(files)/2)+")")

