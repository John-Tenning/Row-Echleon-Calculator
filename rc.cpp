#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> arr
{
    {1,4,5,6,9} , {3,-2,1,4,-1} , {-1 , 0 , -1,-2,-1} ,
    {2,3,5,7,8}
};


void print(){
    printf("--------------------------------------------------------\n");
    for (int i = 0; i < arr.size(); i++)
    {
        for (int j = 0; j < arr[i].size(); j++)
        {
            cout << arr[i][j] << " ";
        }   
        cout << endl;
    }
    printf("--------------------------------------------------------\n");
}

int gcd(int a , int b){
    if(b==0)return a;
    else return gcd(b,a%b);
}


void swap_rows(int i , int  k){
    vector<int>swap = arr[i];
    arr[i] = arr[k];
    arr[k] = swap;
    print();
}

void row_calc(int r  ,int c,int l){
    int coeff_1 = l / arr[c][c];
    int coeff_2 = l / arr[r][c];
    printf("R%d => %d * R%d - %d * R%d\n" , r + 1 ,coeff_2 , r + 1,coeff_1 , c + 1 );
    for(int i = 0;i < arr[0].size();i++)
    {
        arr[r][i] = ((coeff_2)*arr[r][i]) - ((coeff_1) * arr[c][i]);
    }
   
}
// i is row
//j is col
void transform(){
    for(int j = 0; j < arr[0].size(); j++){
        for(int i = j + 1; i<arr.size() ; i++){
            int nonzero = j + 1;
            while(arr[j][j] == 0){
                if(arr[nonzero][nonzero] != 0)
                {swap_rows(j,nonzero);
                printf("R%d <=> R%d\n" , nonzero+1 , j+1);}
                else{nonzero++;}
                // return;
            }

            if(arr[i][j] == 0){
                continue;
            }

            int a = arr[i][j] ;
            int b = arr[j][j] ;

            int gc = gcd(a,b);
            // printf("b => %d\t a => %d\tgcd => %d\n" , a , b , gc);
            int lcm = (a * b) / gc;
            row_calc(i,j ,lcm);
            print();
            
        }
    }

}


int main() 
{
    transform();
    // print();
}