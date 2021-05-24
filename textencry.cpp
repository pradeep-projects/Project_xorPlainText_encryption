#include <bits/stdc++.h>
using namespace std;
#define IOS ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

int getDecimalValue(char x)
{
    if(x>='0' && x<='9')
    { return x-'0'; }

    else if(x=='a')
    { return 10; }

    else if(x=='b')
    { return 11; }

    else if(x=='c')
    { return 12; }

    else if(x=='d')
    { return 13; }

    else if(x=='e')
    { return 14; }

    return 15;
}

char getCharValue(int x)
{
    if(x>=0 && x<=9)
    { return x+'0'; }

    else if(x==10)
    { return 'a'; }

    else if(x==11)
    { return 'b'; }

    else if(x==12)
    { return 'c'; }

    else if(x==13)
    { return 'd'; }

    else if(x==14)
    { return 'e'; }

    return 'f';
}

string encryption(vector<vector<char>> table,int n)
{
    string encryptedText="";
    
    //Encrypting the text by applying columnwise XOR operations//
    for(int i=0;i<n;i++)
    {
        int xorSum=0;
        for(int j=0;j<=i;j++)
        { 
            int numVal= getDecimalValue(table[j][i]);
            xorSum = xorSum^numVal;
        }

        encryptedText+=getCharValue(xorSum);
    }

    for(int i=n;i<2*n-1;i++)
    {
        int xorSum=0;
        for(int j=i-n+1;j<n;j++)
        {
            int numVal = getDecimalValue(table[j][i]);
            xorSum = xorSum^numVal;
        }

        encryptedText+=getCharValue(xorSum);
    }

    return encryptedText;
}

string decryption(vector<vector<char>> &table,string encryptedText)
{
    //Decrypting the encrypted text back to plaintext
    //using XOR properties
    string decryptedText="";
    int len=encryptedText.size();
    int i=len-1;
    int xorSum=0;
    while(i>=len/2)
    {
        int numVal=getDecimalValue(encryptedText[i]);

        int newVal=xorSum^numVal;
        char ch=getCharValue(newVal);
        decryptedText=ch+decryptedText;

        xorSum=xorSum^newVal;
        i--;
    }

    return decryptedText;
}

int main() {
    IOS
    #ifndef ONLINE_JUDGE
    // for getting input from input.txt
    freopen("input.txt", "r", stdin);
    // for writing output to output.txt
    freopen("output.txt", "w", stdout);
    #endif
    
    int t;
    cin>>t;

    while(t--)
    {
        string text;
        cin>>text;

        int n=text.size();

        vector<vector<char>> table(n,vector<char>(2*n-1,'.'));
        //filling the table with text and right shifting the text one place every row
        for(int i=0;i<n;i++)
        {
            int idx=0;
            for(int j=i;j<i+n;j++)
            { table[i][j]=text[idx++]; }
        }
   
        //displaying the shifted plaintext
        cout<<"Plaintext shifting: "<<endl;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<2*n-1;j++)
            { cout<<table[i][j]<<" "; }
        
            cout<<endl;
        }
   
        cout<<endl<<"Plain text is: "<<text<<endl;
   
        string encryptedText=encryption(table,n);
        cout<<"Encrypted text is: "<<encryptedText<<endl;
    
        string decryptedText=decryption(table,encryptedText);
        cout<<"Decrypted text is: "<<decryptedText<<endl<<endl;

    }
   
    return 0;
}