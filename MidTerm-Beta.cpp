#include <bits/stdc++.h>
using namespace std;
// ---- A Drunk Man Will Find His Way Home but a Drunk Bird May Get Lost Forever =) ---- //
// ---- Well , let's See will Drunk Man Find His Way Home ? ---- // 


set<char> Alaem ; // creating a set 



class article // creating a class for article  
{
public : 
    int similaritty(article a) // calculating similaritty percentage 
    {
        if (filename == a.filename) return 0 ; // if they're same , return 0 
        ifstream article1(filename) ; // opening both files 
        ifstream article2(a.filename);
        string word1 , word2 ; 
        int same = 0 ;
        int different = 0 ;
        while (article1 >> word1 and article2 >> word2) // checking articles word by word 
        {
            if(word1 == word2)
            {
                same ++ ; 
            }
            else different ++ ;
        }
        while (article1 >> word1 or article2 >> word2) // counting all words 
        {
            different ++ ; 
        }
        article1.close() ; 
        article2.close() ; 
        return ((same * 100 )/(same + different)) ; // return percentage 
    }
    bool ValSimilaritty(vector<article> Articles) // Validate Similaritty
    {
        int ret = 1 ; 
        for (int i = 0 ; i < Articles.size() ; i++)
        {
            if(similaritty(Articles[i]) > 50)
            {
                ret = 0 ;
            }
        }
        return ret ;
    }
    article(string n , int d , int i , string f , int r) // constructor for article 
    {
        author = n ; 
        date = d ; 
        id = i ; 
        filename = f ; 
        ref = r ;
    }
    bool ValArtName() // validate article name
    {

        return artname.size()<=12 ; 
    }  
    bool ValArtlines() // validate article lines count 
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
    bool ValArtWord() // validate article words count 
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
    bool LineCapCheck() // validate if lines is stared with capital letter or not 
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
    bool ValCapSen() // validate if sentence is stared with capital letter or not 
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
    bool ValAlaem() // validate Punctuation marks 
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
    bool ValPar() // validate paragraph counts 
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
    bool Wlimit() // validate if a word is counted more than 50 times or not 
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



    bool FinalEval(vector<article> F) // final evaluation 
    {
        return ValAlaem() and ValArtlines() and ValArtWord() and LineCapCheck() and ValCapSen() and ValAlaem() and ValPar() and Wlimit() and ValSimilaritty(F) ; 
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
class user  // creating a class for user 
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
    void AddArticle(article a)
    {
        UserArticle.push_back(a) ; 
    }
private : 
    string id;
    string pass;
    vector<article> UserArticle ; 

};
int passcheck(string str) // validate chosen password 
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
    // inserting Punctuation marks to set 
    Alaem.insert('.') ; 
    Alaem.insert(',') ; 
    Alaem.insert('?') ; 
    Alaem.insert('!') ; 
    cout<<"Menu : \n register = 1 \n login = 2 \n" ; 

    bool lf = 0 ; // checks if user is logged in or not 
    int CurrentUser = -1 ; // saving current user index 
    string op ; 
    vector<user> users ; // creating a list of users and they data 
    vector<article> Articles ; // creating a list of articles and they data
    while (op != "exit") 
    {
        if (lf == 0) getline(cin >> ws  , op) ;
        else op = "2" ; 
          

        if(CurrentUser == -1)
        {
            
            if (op == "1")  // sign up 
            {
                string un ; 
                string up ; 
                cout<<"please enter your desired username : \n";
                getline(cin , un) ; 
                cout<<"please enter a strong password \n (your password should have at least one capital letter , one digit and one special character ) \n" ;
                getline(cin , up) ; 
                while (passcheck(up) <= 2) // checks if user password is strong enough or not 
                {
                    cout<<"weak password , try another one \n";
                    getline(cin , up) ; 
                } 

                user newuser (un , up) ; 
                cout<<"succsesfully Done ! \n register = 1 \n login = 2 \n" ;
                users.push_back(newuser) ; // saving new user data 
                
            }
            /* 
            if(op=="4") // test 
            {
             for(int i = 0 ; i < users.size() ; i++)
             {
                 users[i].printuser() ; 
                 cout<<users.size() ; 
             }
            }
            */ 
            if(op == "2") // login 
            {   
                int userindex = -1 ; 
                string un ;
                string up ; 
                cout<<"username : " ; 
                getline(cin , un) ; 

                
                 for(int i = 0 ; i < users.size() ; i++) // finding username among all users 
                 {
                     if(users[i].has_username(un))
                     {
                        userindex = i ; 
                        break ; 
                     }
                 }
                if(userindex != -1 ) // check is chosen username is available or not 
                {
                    lf = 0 ;
                    cout<<"password : " ; 
                    getline(cin , up) ; 
                    if(users[userindex].has_password(up) == true) // checks if chosen password for chosen username is correct or not 
                    {
                        cout<<"login succsecful !\n " ; 
                        CurrentUser = userindex ; 
                        cout<<"menu : \n sumbit your article  = 1 \n evaluate your aricle  = 2 \n logout = 3 \n " ; // menu for logged in user 
                    }
                    else  // if first input was wrong , get a new one 
                    {
                        cout<<"invalid password for this username \n Try again : " ;    
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
                    cout << " invalid username \n" ;   
                    lf = 1 ; 
                }    
            }
        }
            else 
            {
                
                if (op == "1") // submitting article 
                {
                    cout <<"please enter your article name  \n " ; // article name 
                    string esm ;
                    cin>>esm ; 
                    cout<<"please enter a code for your article  \n" ; // article code 
                    int id ; 
                    cin>>id ;                         
                    cout<<"please enter the year of article \n format : 2022\n" ; // article year 
                    int date; 
                    cin>>date ; 
                    cout<<"please enter your article's file name (Eg. :'test.txt')\n" ; // article file name 
                    string filename ; 
                    cin>>filename ;
                    cout<<"please enter your Ref ID , enter 0 for none\n" ; // article ref id
                    int ref ; 
                    cin>>ref ;
                    cout<<"if you did your article with a collaborator please enter their username \n if none enter 0 \n"; // adding collaborator 
                    string colab ; 
                    cin>>colab; 
                    article newarticle(esm , date , id ,filename , ref) ; // creating a new article with given data 
                    Articles.push_back(newarticle) ;    // adding article to all articles 
                    users[CurrentUser].AddArticle(newarticle) ;  // adding article to user articles 
                    if (colab != "0")
                    {
                        int colabindex = -1 ; 
                        for(int i = 0 ; i < users.size() ; i++) // finding username among all users 
                        {
                            if(users[i].has_username(colab))
                            {
                                colabindex = i ; 
                                break ; 
                            }
                        }
                            if (colabindex == -1 ) cout<<"user not found \n" ; 
                            else
                            {
                                users[colabindex].AddArticle(newarticle) ; // adding article to collaborator account 
                                cout<<"Added for them ! \n" ; 
                            } 
                    }                 
                    cout<<"your article has been submitted \n" ; 
                    cout << "menu : \n sumbit your article  = 1 \n evaluate your aricle  = 2 \n logout = 3 \n " ; 

                }
                if (op =="2") // checks if your article has been verified or not 
                {
                    cout<<"please enter your article code \n" ; 
                    int id ; 
                    cin>>id ; 
                    for (int i = 0 ; i < Articles.size() ; i++)
                    {
                        if(Articles[i].Has_id(id))
                        {
                            if(Articles[i].FinalEval(Articles)) 
                            {
                                cout<<"your artcile has been verified ! =) \n" ; 
                                cout<<"menu : \n sumbit your article  = 1 \n evaluate your aricle  = 2 \n logout = 3 \n " ; 
                            }
                            else 
                            {
                                cout<<"your article has not been verified !  \n" ; 
                                cout<<"menu : \n sumbit your article  = 1 \n evaluate your aricle  = 2 \n logout = 3 \n " ; 
                            }
                        }
                    }

                }
                if(op =="3")
                {
                    CurrentUser = -1 ; // back to normal menu 
                    cout<<"Menu \n register = 1 \n login = 2 \n" ; 

                }

            }
        }
    

    
    return 0 ;    
}

// Well Well , It Seems Our Drunk Man Found His Way Home =))))) 
// Uh... , See Ya Soon Mate 
// Good Luck  
