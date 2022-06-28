#include <bits/stdc++.h>

using namespace std;


set<char> Alaem ; 
class user 
{
public : 
    void printuser()
    {
        cout<<id<<"\n"<<pass<<"\n" ; 
    }
    bool has_username(string un) 
    {
        return un == id ; 
    }
    bool has_password(string up) 
    {
        return up == pass ; 
    }
    user(string i , string p)
    {
        id = i ; 
        pass = p ;
    }

private : 
    string id;
    string pass;

        
};

class article 
{
public : 
    article(string n , int d , int i , string f , int r)
    {
        author = n ; 
        date = d ; 
        id = i ; 
        filename = f ; 
        ref = r ;
    }
    bool ValArtName()
    {

        return artname.size()<=12 ; 
    }  
    bool ValArtlines()
    {

        string line ; 
        ifstream file ;
        file.open(filename.c_str()) ;
        int lines = 0 ; 

        while(getline(file , line))
        {
            lines ++ ;
        }
        return lines >= 3 ; 
    }
    bool ValArtWord()
    {
        ifstream file ;
        file.open(filename.c_str()) ;
        int Words = 0 ; 
        string Word ; 
        while(file >> Word)
        {
            Words ++ ;
        }
        return 5000 > Words and Words > 100; 
    }
    bool LineCapCheck()
    {
        int lines ; 
        string line ;
        ifstream file ;
        file.open(filename.c_str()) ;
        while(getline(file , line))
        {
            if(islower(line[0])) return false ;
        }
        return true ; 
    }
    bool ValCapSen()
    {

        string line ;
        ifstream file ;
        file.open(filename.c_str()) ;
        while(getline(file , line))
        {
            for (int i = 0 ; i < line.size()-1 ; i++)
            {
                if(Alaem.find(line[i])!=Alaem.end() and line[i]!=',')
                {
                    if(islower(line[i+2])) return false ;         
                }         
            }
        }        
        return true ;  
    }
    bool ValAlaem() 
    {

        ifstream file ;
        file.open(filename.c_str()) ;
        string line ;
        while(getline(file , line))
        {
            line += " " ; 
            bool flag = 0 ;
            for (int i = 0 ; i < line.size() ; i++)
            {
                if(Alaem.find(line[i])!=Alaem.end())
                {
                    if (flag == 1) return false ; 
                    flag = 1 ; 
                    if(line[i+1] != ' ') return false ; 
                    
                } 
                else if (line[i]!=' ') flag = 0 ; 

            }
        }
        return true ;  

    }
    bool ValPar()
    {
 
        string line ;
        ifstream file ;
        file.open(filename.c_str()) ;
        int depth = 0 ; 
        while(getline(file , line))
        {
            for(int i = 0 ; i < line.size() ; i++)
            {
                if(line[i] == '(') depth ++ ; 
                else if (line[i] == ')') depth -- ; 
                if (depth < 0) return false ; 
            }
        }
        if (depth > 0) return false ;
        return true ;  
    }
    bool Wlimit() 
    {

        map<string,int> WordCount ;
        ifstream file ;
        file.open(filename.c_str()) ;
        int Words = 0 ; 
        string Word ; 
        while(file >> Word)
        {
            WordCount[Word] ++ ; 
            if(WordCount[Word] > 50 ) return false ; 
        } 
    return true ;        
    }    
    bool FinalEval()
    {
        return ValAlaem() and ValArtlines() and ValArtWord() and LineCapCheck() and ValCapSen() and ValAlaem() and ValPar() and Wlimit() ; 
    }
    bool Has_id(int i)
    {
        return i == id ;
    }

private : 
    int id ; 
    int date ; 
    int CodeRahgiri ; 
    int ref ; 
    string author ; 
    string artname ; 
    string filename ; 




};
int passcheck(string str)
{ 
    int l_case=0, u_case=0, digit=0, special=0;
    int l=str.length(),i;
  
  for(i=0;i<l;i++)
  {
        if(islower(str[i]))
        l_case=1;
        if(isupper(str[i]))
        u_case=1;
        if(isdigit(str[i]))
        digit=1;
        if(!isalpha(str[i]) && !isdigit(str[i]))
        special=1;  
  }
  return(l_case + u_case + digit + special) ; 
};









int main()
{
    Alaem.insert('.') ; 
    Alaem.insert(',') ; 
    Alaem.insert('?') ; 
    Alaem.insert('!') ; 
    cout<<"Menu \n register = 1 \n login = 2 \n" ; 

    bool lf = 0 ; 
    int CurrentUser = -1 ;
    string op ; 
    vector<user> users ; 
    vector<article> Articles ; 
    while (op != "exit") 
    {
        if (lf == 0) getline(cin >> ws  , op) ;
        else op = "2" ; 
          

        if(CurrentUser == -1)
        {
            
            if (op == "1")
            {
                string un ; 
                string up ; 
                cout<<"username mad nazar khod ra vared konid : \n";
                getline(cin , un) ; 
                cout<<"password khod ra entekhab konid : \n";
                getline(cin , up) ; 
                while (passcheck(up) <= 2)
                {
                    cout<<"weak password , try another one \n";
                    getline(cin , up) ; 
                } 

                user newuser (un , up) ; 
                cout<<"succsesfully Done ! \n register = 1 \n login = 2 \n" ;

                users.push_back(newuser) ; 
                
            }
            if(op=="4")
            {
             for(int i = 0 ; i < users.size() ; i++)
             {
                 users[i].printuser() ; 
                 cout<<users.size() ; 
             }
            }

            if(op == "2")
            {   
                int userindex = -1 ; 
                string un ;
                string up ; 
                cout<<"username : " ; 
                getline(cin , un) ; 

                
                 for(int i = 0 ; i < users.size() ; i++)
                 {
                     if(users[i].has_username(un))
                     {
                        userindex = i ; 
                        break ; 
                     }
                 }
                if(userindex != -1 )
                {
                    lf = 0 ;
                    cout<<"password : " ; 
                    getline(cin , up) ; 
                    if(users[userindex].has_password(up) == true) 
                    {
                        cout<<"login succsecful !\n " ; 
                        CurrentUser = userindex ; 
                        cout<<"menu : \n ersal maghale = 1 \n rahgiri maghale = 2 \n logout = 3 \n " ;
                    }
                    else 
                    {
                        cout<<"invalid password for this username \n password : " ;  
                        int flag = 0 ; 
                        while (flag == 0)
                        {
                            
                            getline(cin , up) ; 
                            if(users[userindex].has_password(up) == true) 
                            {
                                cout<<"login succsecful !\n " ; 
                                flag = 1 ; 
                                CurrentUser = userindex ; 
                                cout<<"menu : \n ersal maghale = 1 \n rahgiri maghale = 2 \n logout = 3 \n " ;                            
                            }
                            else
                            {
                                cout<<"invalid password for this username \n password : " ;  
                            }
                        }
                        
                    }
                }
                
                else 
                {
                    lf = 1 ; 
                }    
            }
        }
            else 
            {
                
                if (op == "1")
                {
                    cout <<"esm maghale khod ra vared konid \n " ;
                    string esm ;
                    cin>>esm ; 
                    cout<<"shenase maghale ra vared konid\n" ; 
                    int id ; 
                    cin>>id ;                         
                    cout<<"sal maghale ra vared konid \n format : 2022\n" ; 
                    int date; 
                    cin>>date ; 
                    cout<<"esm file khod ra vared konid\n" ; 
                    string filename ; 
                    cin>>filename ;
                    cout<<"refrence haye khod ra vared konid\n" ; 
                    int ref ; 
                    cin>>ref ; 
                    article newarticle(esm , date , id ,filename , ref) ; 
                    Articles.push_back(newarticle) ; 
                    cout<<"Maghale shoma sabt shod \n" ; 

                }
                if (op =="2")
                {
                    cout<<"shenase maghale khod ra vared konid\n" ; 
                    int id ; 
                    cin>>id ; 
                    for (int i = 0 ; i < Articles.size() ; i++)
                    {
                        if(Articles[i].Has_id(id))
                        {
                            if(Articles[i].FinalEval()) cout<<"Maghale shoma taiid shode ast\n" ; 
                            else cout<<"Maghale shoma taiid nashode ast \n" ; 
                        }
                    }

                }
                if(op =="3")
                {
                    CurrentUser = -1 ; 
                    cout<<"Menu \n register = 1 \n login = 2 \n" ; 

                }

            }
        }
    

    
    return 0 ;    
}