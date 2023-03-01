#include <bits/stdc++.h>
using namespace std;
#define mmst(x , v) memset(x , v , sizeof(x))
#define             el '\n'
#define             ll long long
const int N=105+5,M=1e5+5;
//----------------------------------------------------
/*
void print_triangle(int rows){
    if(rows<=0)return;
    print_triangle(rows-1);
    for (int i = 0; i < rows; ++i) {
        cout<<'*';
    }
    cout<<el;
}
*/

/*
//5
//1+f(16) -> 1+1+f(8) -> 1+1+1+f(4) -> 1+1+1+1+f(2)
int f3n(int n){
    if(n==1)return 1;
    if(n&1)return 1+f3n(3*n +1);
    else return 1+f3n(n/2);
}
 */

/*
//123
//12->3
//print what in the left then what in the right.
void print_num(int num) {
    if (num) {
        print_num(num / 10);//print the left part
        cout << num % 10;//then print the last digit
    }
}

//7
//3->1  ,, 1->11 ,, 0->111
void print_bits(int n){
    if(n){
        print_bits(n/2);
        cout<<n%2;
    }
}
 */

/*const int n=2;
int arr[n][n];
bool valid(int i,int j){
    if(i>=n || j>=n)return false;
    return true;
}
int max_sum(int i, int j){
    if(!valid(i,j))return 0;
    if (i==n-1 && j==n-1)return arr[i][j];
    int right=0,down=0;
    right=max_sum(i+1,j);//down
    down=max_sum(i,j+1);//right
    return arr[i][j]+max(right,down);
}*/

/*
const int n=2;
char maze[n][n];
bool visited[n][n];

bool is_valid(int i, int j){
    if(i<0 || i>=n || j<0 || j>=n)return false;
    return true;
}
bool there_a_path(int i,int j) {
//when maze[i][j]='.' there no return i will go to the condition from begin again
//when = 'X' there was return false so i will stop and go back to the condition and the condititon not achieved so i will go to the
    //next one
//when ='E' there return true so i will go back to the condition and it will achieved so it will return true so i will go back again
    //to the condition i came from and it will achived and go back untill go to where i start and stop.
    if (!is_valid(i, j) || maze[i][j] == 'X' || visited[i][j])return false;

    visited[i][j] = true;

    if (maze[i][j] == 'E')return true;//when this achieved i go back to the condition

    if(there_a_path(i + 1, j))return true;//d
    if(there_a_path(i, j + 1))return true;//r
    if(there_a_path(i, j - 1))return true;//l
    if(there_a_path(i - 1, j))return true;//u


    visited[i][j] = false;

    return false;
}
*/

char maze[N][N];
int n;
bool vis[N][N];
bool valid(int i,int j){
    return (i>=0 && i<n && j>=0 && j<n);
}
int c;
void bath(int i, int j) {
    if(!valid(i,j) || maze[i][j]=='X' || vis[i][j])return;
    c++;
    vis[i][j]= true;

    bath(i+1,j);
    bath(i-1,j);
    bath(i,j+1);
    bath(i,j-1);

}
void mymain() {

/*    int n; cin>>n;
    print_triangle(n);
    cout<<f3n(n);
    print_num(n);
    print_bits(n);*/

/*
 start from 0,0 go right or down to n,n and get max sum u can get.
2 4
1 1
 7

    for(int i=0;i<n; i++){
        for (int j = 0; j < n; ++j) {
            cin>>arr[i][j];
        }
    }
    cout<<max_sum(0,0);
*/

/*
    int x,y;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; j++) {
            cin >> maze[i][j];
            if (maze[i][j] == 'S')x = i, y = j;
        }
    }
    cout<<there_a_path(x,y);

S X
. E
    */
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; ++j) {
            cin >> maze[i][j];
        }
    }
    int mx=0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if(!vis[i][j]){
                c=0;
                bath(i,j);
                mx= max(c,mx);
            }
        }
    }
    cout<<mx<<el;




}
//----------------------------------------------------
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cin.tie(0);
    cin.sync_with_stdio(0);
    int t=1; //cin>>t;
    for(int tt=0;tt<t;tt++){;mymain();}
    return 0;
}