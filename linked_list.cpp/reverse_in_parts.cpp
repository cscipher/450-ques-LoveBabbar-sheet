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
    Node* head;
    public:
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
            cout<<endl;
        }

        void reverseInParts(int k){
            Node* curr = head;
            Node* thead = head;
            Node* prev = nullptr;
            Node* nxt = nullptr;
            while(k--){
                nxt = curr->next;
                curr->next = prev;
                prev = curr;
                curr = nxt;
            }
            head = prev;
            prev = nullptr;
            // pn(head);
            while(curr!=nullptr){
                nxt = curr->next;
                curr->next = prev;
                prev = curr;
                curr = nxt;
            }
            thead->next = prev;
        }

        
};

int main() {

    IOS;
    LinkedList LL = LinkedList();

    vi arr = {5,9,9,3,5,6,6,2,8,2};
    int n = 2;

    for(int i=0;i<arr.size();i++) LL.insert(i,arr[i]);
    
    LL.display();
    LL.reverseInParts(n);
    LL.display();

}