#include<iostream>
#include<string>
#include<cstring>
#include<stdlib.h>


using namespace std;

void shift(char* text,int key)
{
        int x,y;
        int temp;
        int temp1;
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
        cout<<"Cipher Text:\n";
        cout<<"\t--------------------\n";
        cout<<"\t";
        for(int i=0;i<=strlen(text);i++)
        {
             cout<<text[i];
        }

}




void hill(char* text)
{
        int k=0;
        int A[2][1];
        int mul[2][1]={0};
        int H[2][2];
        int len;
        char ch;

        len=strlen(text);
        if(len%2!=0)
        {
            cout<<"\nYou need to Enter an extra character\n";
            cin>>ch;
            text[len]=ch;
            text[len+1]='\0';
        }


        cout<<"\nEnter Key for hill cipher\n";
        for(int i = 0; i < 2; ++i)
        {
            for(int j = 0; j < 2; ++j)
            {
                cin >> H[i][j];
            }
        }



        while(text[k]!='\0')
        {

            memset(mul, 0, sizeof(mul[0][0]) * 2 * 1);


                for(int l=0;l<2;l++)
                {
                    for(int m=0;m<1;m++)
                    {
                        if(text[k]>=97 && text[k]<=122)
                        {
                            A[l][m]=text[k]-97;
                        }
                        else if(text[k]>=65 && text[k]<=90)
                        {
                            A[l][m]=text[k]-65;
                        }
                    k++;
                    }

                }


            for(int a=0;a<2;a++)
            {
                for(int b=0;b<1;b++)
                {
                    for(int c=0;c<2;c++)
                    {
                        mul[a][b]=mul[a][b]+H[a][c]*A[c][b];

                    }

                }
            }
            k=k-2;
            for(int l=0;l<2;l++)
            {
                    for(int m=0;m<1;m++)
                    {
                        mul[l][m]=mul[l][m]%26;

                        if(text[k]>=97 && text[k]<=122)
                        {
                            text[k]=mul[l][m]+97;
                        }
                        else if(text[k]>=65 && text[k]<=90)
                        {
                            text[k]=mul[l][m]+65;
                        }

                    k++;

                    }

            }


        }
        cout<<"\n\tHILL Cipher Text:\n";
        cout<<"\t--------------------\n";
        cout<<"\t";
        for(int i=0;i<=strlen(text);i++)
        {
             cout<<text[i];
        }

}



void vigenere(char* text,char* key)
{
            int x,y;
            int i=0;
            int j;
            int temp;
            int temp1;

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


        cout<<"Cipher Text:\n";
        cout<<"\t--------------------\n";
        cout<<"\t";
        for(int i=0;i<=strlen(text);i++)
        {
             cout<<text[i];
        }

}






int main()
{
    int n;
    char mesg[100];
    int skey;
    char vkey[100];
    char* cipher[100];

    /*THE ENCRYPTION CAN WORK IN DIFFERENT COMBINATION AS THE CIPHERS ARE UPDATED IN THE ENCRYPTED MESSAGE ITSELF*/

    cout<<"\n\t\t***************DATA ENCRYPTION******************\n";
    cout<<"\t\t-------------------------------------------------\n";
    cout<<"\t\tTo encrypt your message using shift cipher Press:-1\n";
    cout<<"\t\tTo encrypt your message using hill cipher Press:-2\n";
    cout<<"\t\tTo encrypt your message using vigenere cipher Press:-3\n";
    cout<<"\t\tYou can exit by pressing:-'0'\n\n";


    cout<<"-Enter Your Message please(without spaces)-\n";
    cin.getline(mesg,sizeof(mesg));

    while(1)
    {
        cout<<"\n\nEnter Your option for encryption(1,2,3) or can quit(0):";
        cin>>n;
        switch(n)
        {
            case 1:
                cout<<"\nEnter Your key for shift cipher:\n";
                cin>>skey;
                cout<<"\n\tSHIFT ";
                shift(mesg,skey);
                continue;
            case 2:
                hill(mesg);
                continue;
            case 3:
                cout<<"\nEnter Your key for vigenere cipher:\n";
                cin>>vkey;
                cout<<"\n\tVIGENERE ";
                vigenere(mesg,vkey);
                continue;
            case 0:
                system("cls");
                cout<<"\n\n\t\tThank You for Trusting Us!!!\n\n\n\n";
                exit(0);
            default:
                cout<<"\n\tEntered Wrong Option see to it!!!";

        }

    }

return 0;
}
