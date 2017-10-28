#include<iostream>
#include<string>
#include<cstring>
using namespace std;

class vigenere_cipher
{
public:
    char key[100];
    char text[100];
    int temp;
    int temp1;
public:
    void usr_input()
    {
        cout<<"\nEnter Your plain text:\n";
        cin.getline(text,sizeof(text));
        cout<<"Enter Your Key:\n";
        cin.getline(key,sizeof(key));

    }
    void vigenere()
    {
            int x,y;
            int i=0;
            int j;

            for(int i=0;i<=strlen(key);i++)
            {
                if(key[i]>=97 && key[i]<=122)
                    {
                        key[i]=key[i]-97;
                    }
                    else if(key[i]>=65 && key[i]<=90)
                    {
                        key[i]=key[i]-65;
                    }
            }
            i=0;



            for(int j=0;j<=strlen(text);j++)
            {
                if(key[i]=='\0' && text[j]!='\0')
                {
                    i=0;

                }

                if(text[j]>=97 && text[j]<=122)
                {
                    x=text[j]+key[i];
                    if(x>122)
                    {
                        temp=x-122;
                        text[j]=96+temp;
                        i++;
                    }
                    else{
                        text[j]=text[j]+key[i];
                        i++;
                    }

                }
                else if(text[j]>=65 && text[j]<=90)
                {
                    y=text[j]+key[i];
                    if(y>90)
                    {
                        temp1=y-90;
                        text[j]=64+temp1;
                        i++;
                    }
                    else{
                        text[j]=text[j]+key[i];
                        i++;
                    }

                }
                else
                {
                    text[j]=text[j];
                    continue;
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
    vigenere_cipher v1;

    v1.usr_input();
    v1.vigenere();
}

