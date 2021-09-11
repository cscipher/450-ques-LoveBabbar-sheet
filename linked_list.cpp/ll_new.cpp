#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef vector<char> vc;
typedef vector<double> vd;
typedef vector<string> vs;
typedef pair<int, int> pii;
typedef unordered_map<char, int> umci;
typedef unordered_map<char, int> mci;

#define all(c) (c).begin(),(c).end()
#define rall(c) (c).rbegin(),(c).rend()
#define loop(i,a,n) for(ll i=a;i<n;i++)
#define Rloop(i,a,n) for(ll i=n-1;i>=a;i--)
#define pb push_back
#define first F
#define mp make_pair
#define second S
#define IOS  ios_base::sync_with_stdio(0);cin.tie(0); cout.tie(0)
#define PI 3.1415926535897932384626433832795
#define MOD 1e5+7
#define pn(a) cout<<a<<endl
#define pc(a) cout<<a<<" "

class Node{
	public:
		int v;
		Node *next;
		Node(){
			next = NULL;
		}
};

class LinkedList {
    public:
        Node* head;
        LinkedList(){
			head = NULL;
		}
        void insertAtBegin(int val){
            Node* temp = new Node();
            temp->v = val;
            temp->next = head;
            head = temp;
            return;
        }
        void insertAtEnd(int val){
            Node* temp = new Node();
            temp->v = val;
            if(head == NULL) {
                head = temp;
                return;
            } else {
                Node* ptr = head;
                while(ptr!=NULL){
                    ptr = ptr->next;
                }
                ptr->next = temp;
                return;
            }

            
        }
        void insert(int p, int val){
            Node* temp = new Node();
            temp->v = val;
            if(p==0){
                temp->next = head;
                head = temp;
                return;
            } else {
                Node* ptr = head;
                while(p>1){
                    ptr = ptr->next;
                    p--;
                }
                temp->next = ptr->next;
				ptr->next = temp;
            }
        }

        void removeAtFirst() {
            pc("Deleted val : ");
            pn(head->v);
            Node* temp = nullptr;
            temp = head;
            head = head->next;
            delete(temp);
        }

        void removeAtLast() {
            Node* ptr = head;
            while(ptr->next!=nullptr){
                ptr = ptr->next;
            }
            pc("deleted val:");
            pn(ptr->next->v);
            delete(ptr->next);
        }
        void remove(int index) {
            Node* ptr = head;
            if(index == 0){
                removeAtFirst();
            }
            while(index>1){
                ptr = ptr->next;
                index--;
            }
            pc("deleted val:");
            pn(ptr->next->v);
            Node* temp = ptr->next->next;
            delete(ptr->next);
            ptr->next = temp;
        }

        void display(){
            Node* ptr = head;
            while(ptr!=nullptr){
                pc(ptr->v);
                ptr = ptr->next;
            }
        }
        
        int LengthLL(Node *x){
            int c=0;
            while(x){
                c++;
                x=x->next;
            }
            return c;
        }

        bool checkPalindrome(Node *ptr){
            stack<int> st;
            int l = LengthLL(ptr);
            loop(i,0,ceil(l/2)){
                st.push(ptr->v);
                ptr = ptr->next;
            }
            loop(i,ceil(l/2),l){
                if(!st.empty()) st.pop();
                ptr=ptr->next;
            }
            return st.empty();

        }
};


int main() {


    IOS;
    LinkedList LL = LinkedList();
    LL.insert(0,20);
    LL.insert(1,25);
    // LL.insert(2,25);
    LL.insert(2,25);
    LL.insert(3,20);
    LL.display();
    cout<<endl;
    pn(LL.checkPalindrome(LL.head));
    // pn("Deleted at i=2");
    // LL.remove(2);
    // LL.display();

}