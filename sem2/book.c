#include<iostream>
using namespace std;

class Book{
    
    public:
        string title;
        string author;
        string pub;
        int price;
        int stock;
        
        static int succ;
        static int unsucc;
        
        void show(){
            cout << "\nName:"<< title;
            cout << "\n author:"<<author;
            cout <<"\npublisher:"<<pub;
            cout <<"\nprice:"<<price;
            cout << "\n stock:"<<stock;
        }
        
        void reduce(){
            stock--;
        }
        
    
};

int linear(Book book[10],int num,string title){
    for(int i=0;i<num;i++){
        if(book[i].title==title){
            cout << "found";
            return i;
        }
        cout << "i";
    }
    return -1;
}

int Book::succ=0;
int Book::unsucc=0;
int main(){
//    string str;
  //  getline(cin,str);
  //  cout  << str;
  int num=0;
  Book book[10];
 
 Book stat;


  int ch=0;
  int b=1;
  while(b){
      cout << "\n===MENU===\n";
      cout << "1)add\n2)update\n3)search\n4)get\n5)transactions\n6)exit\n";
      cout <<"choice:";
      cin >> ch;
      switch(ch){
           case 1:cin.ignore();
                  cout << "name:";
                  getline(cin,book[num].title);
                  cout << "author:";
                  getline(cin,book[num].author);
                  cout <<"publisher:";
                  getline(cin,book[num].pub);
                  cout << "price:";
                  cin >> book[num].price;
                  cout << "stock:";
                  cin >> book[num].stock;
                  cout << "\n======================\n";
                  book[num].show();
                  num++;
                  break;
            case 2:{cout << "give title:";
                    string t;
                    cin.ignore();
                    getline(cin,t);
                    int find=linear(book,num,t);
                    if(find!=-1){
                        cout << "name:";
                          getline(cin,book[find].title);
                          cout << "author:";
                          getline(cin,book[find].author);
                          cout <<"publisher:";
                          getline(cin,book[find].pub);
                          cout << "price:";
                          cin >> book[find].price;
                          cout << "stock:";
                          cin >> book[find].stock;
                          cout << "\n======================\n";
                          book[find].show();
                    }else{
                        cout << "not found";
                    }
                    break;
            }
            case 3:{cout << "give title:";
                    string t;
                    cin.ignore();
                    getline(cin,t);
                    int find=linear(book,num,t);
                    if(find!=-1){
                          book[find].show();
                    }else{
                        cout << "not found";
                    }
                    break;
                
            }
            case 4:{cout << "give title:";
                    string t;
                    cin.ignore();
                    getline(cin,t);
                    int find=linear(book,num,t);
                    if(find!=-1){
                          if(book[find].stock > 0){
                              book[find].reduce();
                              stat.succ+=1;
                              
                          }else{
                              stat.unsucc+=1;
                          }
                    }else{
                        cout << "not found";
                    }
                    break;
                
            }
            case 5:{
                cout << " Successful transaction:" << stat.succ;
                cout << "\n Unsuccessful transaction:" << stat.unsucc;
                break;
            }
            case 6:b=0;break;
            default : cout << "wrong";
      }
  }
  

  
}
