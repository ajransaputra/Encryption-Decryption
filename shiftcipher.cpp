#include<iostream>
#include<string>
#include<cstring>
using namespace std;
class shift_cipher
{
public:
    int key;
    char text[100];
    int temp;
    int temp1;
public:
    void usr_input()
    {
        cout<<"\nEnter Your plain text:\n";
        cin.getline(text,sizeof(text));
        cout<<"Enter Your Key:\n";
        cin>>key;

    }
    void shift()
    {
        int x,y;
        for(int i=0;i<=strlen(text);i++)
        {
            if(text[i]>=97 && text[i]<=122)
            {
                x=text[i]+key;
                if(x>122)
                {
                    temp=x-122;
                    text[i]=96+temp;
                }
                else{
                    text[i]=text[i]+key;
                }

            }
            else if(text[i]>=65 && text[i]<=90)
            {
                y=text[i]+key;
                if(y>90)
                {
                    temp1=y-90;
                    text[i]=64+temp1;
                }
                else{
                    text[i]=text[i]+key;
                }

            }
            else
            {
                text[i]=text[i];
            }

        }
        cout<<"\nCipher Text:\n";
        for(int i=0;i<=strlen(text);i++)
        {
             cout<<text[i];
        }

    }

};
int main()
{
    shift_cipher s1;

    s1.usr_input();
    s1.shift();
}
