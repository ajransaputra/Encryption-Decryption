#include<iostream>
#include<string>
#include<cstring>

using namespace std;

class hill_cipher
{
public:
    char text[100];
    int len;
    char ch;

public:
    void usr_input()
    {

        cout<<"\nEnter Your Text:\n";
        //cin.ignore();
        cin.getline(text,sizeof(text));
        len=strlen(text);
        cout<<len;
        if(len%2!=0)
        {
            cout<<"Enter an extra character\n";
            cin>>ch;
            text[len]=ch;
            text[len+1]='\0';
        }
    }

    void hill()
    {
        int k=0;
        int A[2][1];
        int mul[2][1]={0};
        int H[2][2];
        /*{
            (5,3),
            (2,1)
        };*/
        cout<<"Enter Key\n";
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
                    cout<<mul[a][b]<<endl;
                }
            }
            k=k-2;
            for(int l=0;l<2;l++)
            {
                cout<<text[k];
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
        cout<<"\nCipher Text:\n";
        for(int i=0;i<=strlen(text);i++)
        {
             cout<<text[i];
        }
    }




};

int main()
{
    hill_cipher h1;

    h1.usr_input();
    h1.hill();
}

