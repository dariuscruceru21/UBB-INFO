#include <iostream>
using namespace std;



/*struct Client {
    int num;
    string name;
    int postalCode;
    string location;

}a[4];*/

/*void multiplyMatrici(int n){
    int i,j;
    int matrix[n][n];
    int colPr = 1;
    int colsec = 1;
    int tr1 = 1;
    int tr2 = 1;
    int det = 0;
    for(i=0;i<n;i++){
        for(j=0;j<n;j++)
            cin>>matrix[i][j];
        cout<<endl;
    }

    for(i=0;i<n;i++){
        for(j=0;j<n;j++)
            if(i == j)
                colPr = colPr * matrix[i][j];
            if (i + j == n - 1)
                colsec = colsec * matrix[i][j];

    }
    tr1 = matrix[0][1] * matrix[1][2] * matrix[2][0];
    tr2 = matrix[0][1] * matrix[1][0] * matrix[2][2];
    det = tr1 + colPr - (tr2 + colsec);
    cout<<"Determinantul este "<< det;



}*/



class bankAccount{

    private:
        int money = 0;

    public:
        void addSum(int e){
            this->money += e;
        }
        void takeMoney(int e){
            this->money -= e;
        }
        void balance(){
            cout << this->money;
        }
};



int main(){

        /*
        cin >> a[0].num;
        cin >> a[0].name;
        cin >>a[0].postalCode;
        cin>>a[0].location;
        cout<< a[0].num;
        cout<<a[0].name;
        cout<<a[0].postalCode;
        cout<<a[0].location;*/
        //multiplyMatrici(2);
        bankAccount a;
        a.addSum(40000);
        a.takeMoney(10);
        a.balance();


        return 0;

}