EPSILON = "#"
#code for printing epsilon
#print u"\u03B5"

def checkEpsilon(a,dict):
    if EPSILON in dict[a]:
        return True
    else:
        return False

def First(a,dict,result,ep):  
    tep=False    
    ep=False   
    flag =0
    if not(a.isupper()):
        result.add(a)
        return False
    if dict.get(a) == None :
        print "Incomplete Productions"
        return 
    p = dict[a].split("|")
    for x in p:
        if not(x[0]==a):
            for ch in x:  
                flag=0          
                if(not(ch.isupper())):
                    if ch != EPSILON:
                        result.add(ch) 
                        ep=False   
                        flag=1                
                        break                    
                else:
                    First(ch,dict,result,ep)
                    if not(checkEpsilon(ch,dict)):                        
                        ep=False
                        flag=1
                        break                                            
                    else:
                        if not(ep):
                            ep=True
                if(flag==1):
                    break
            if ep and not(tep):
                tep=ep
                
        else:
            print "LEFT RECURSIVE Grammar"
    if (checkEpsilon(a,dict)):
        tep=checkEpsilon(a,dict)
    # print result,tep
    return tep 



def Follow(a,dict,result,startSymbol):
    keys = dict.keys()    
    if (a in keys):
        if(a==startSymbol):
            result.add("$")
        for x in keys:
            rSide = dict[x]             
            for i in range(0,len(rSide)):
                if(a==rSide[i]):
                    # print rSide[i]           
                    if(i+1!=len(rSide)):  
                        if rSide[i+1] != '|' :
                            flag =0
                            tempResult = set()
                            ep = False 
                            for j in range(i+1,len(rSide)):
                                if(rSide[j] =='|'):
                                    break
                                if First(rSide[j],dict,result,ep):
                                    # print result
                                    flag=1
                                    continue                                    
                                else :
                                    # print result   
                                    flag = 0                                                                                       
                                    break
                            if flag==1 :
                                if(x!=a):                                
                                    Follow(x,dict,result,startSymbol)        
                                # print result
                        else:
                            if(x!=a):
                                Follow(x,dict,result,startSymbol)
                            # print result
                    else:
                        if(x!=a):
                                Follow(x,dict,result,startSymbol)
                        # print result                 
    else:
        print "Productions are incomplete"



def main():
    print "Enter number of production"
    n = input()    
    a={}
    startSymbol = ""
    result = set()
    for i in range(0,n):
        x = raw_input()
        y = x.strip().split("->")          
        if i==0:
            startSymbol = y[0]
        if a.get(y[0]) == None :
            if y[0].isupper() :
                a[y[0]]=y[1]        
            else:
                print "Not valid Production"
        else:
            sep = "|"
            temp = a[y[0]] 
            temp = temp,y[1]
            a[y[0]]=sep.join(temp)    
    ch = ""
    # print "Enter Terminal to find Follow"
    # ch = raw_input().strip().split()[0]       
    # result.clear()
    # Follow(ch,a,result,startSymbol)
    # print result  
    # result.clear() 

    while True and ch!='0' :
        print "Find First exit(0)"
        ch = raw_input().strip().split()[0]   
        if(ch=="0"):
            break
        ep = False 
        if First(ch,a,result,ep):
            result.add(EPSILON)
            print result 
        else :
            print result
        print "Find Follow exit(0)"
        ch = raw_input().strip().split()[0]   
        if(ch=="0"):
            break
        result.clear()
        Follow(ch,a,result,startSymbol)
        print result  
        result.clear()  


main()