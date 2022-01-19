//������ ����� ��� ������ ���� ���� ���� ��� �������� � ��� ���� ����� ��� �� link list ���� �� 
#include<iostream>
#include<string>
using namespace std;
//��� ���� � �������� ����� ����� ��� ���� ������� ���� �������
struct Node {
	string name, add;
	float  salary;
	long long int num_phone;
	int  degree;
	Node* next;
};
/*��� ������ ���� �� ����� ������ ��� �������� � ����� ������ ����� � ����� �����*/
class Super_link_listed {
	/*��� ���� ������ ������� ����� ������� ���� ����� 
	�� ����� �� ��� ���� �������� �� ����� ������� ��� �����  */
	Node* first=NULL;
	Node* last=NULL;
	int length = 0;//���� ��� �������� 
public:	
	//���� ������ ��� ��� ������ ������ ��� �� 
	int is_empty() {
		return length == 0;
	}
	/*��� ������ ���� ���� ������ �������� �� ����� � ���� ��� ������� ���� ������� ���� ����� �� ������� ������ */
	void push_back(string n,string ad,float sal,long long int num,int deg) {
		Node* newNode = new Node;//���� ������ ����� ���� 
		newNode->name= n; newNode->add = ad; newNode->salary = sal; newNode->num_phone = num; newNode->degree = deg;//������� ������� ������� ������
		//��� ���� ��� ��� ���� ����� �� ��� �� �� 
		if (is_empty()) {
			//��� �� ��� ���� ������ �� ��� ������ ������� ������ �� ��� ����� 
			first = last=newNode;//����� ������� ������ ������ ��� � ��� ����� 
			last->next = NULL;//���� ���� ������ �������� �������� ������ 
			length++;
		}
		else {
			//��� �� ��� ���� ������ �� ��� ����� ������� ������� ������ �� ����� ������� 
			last->next = newNode;//��� �� ������� ������ �� ���� ���� ����� ������ ������ ������� ������ ����� ������� ������ ���� ��� ������� ������ 
			last = newNode;//��� ���� ������� ������ �� ������� ������ 
			last->next = NULL;//��� ���� ������� ������ �������� ������� ��� 
			length++;
		}

	}
	//���� ��� ���� ���� �� ����� �������� �� ��� ����� �� ������
	void output() {
		Node* curr = first;//��� ���� ������ ���� ����� ����� ��� ������� ����� 
		while (curr != NULL) {
			cout << curr->name << "   " << curr->num_phone << "   " << curr->salary << "   " << curr->degree << "   " << curr->add<<endl;
			curr = curr->next;//��� ���� ������ ������� ��� ������� ������ 
		}
	}   
	//��� ������ ���� ������ ��� ��� ������ �� ���� ����
	void serch_by_name(string N){
		Node* curr = first;
		int conter = 1;
		while (curr != NULL){
			if (curr->name == N) {
				cout << "Found it at position :" << conter<<endl;//��� ��� �� ����� ����� ����� ������� 
				break;
			}
			conter++;
			curr = curr->next;
		}
		if (curr == NULL) {
			cout << "We don't find it :("<<endl;
		}
		
	}
	//������ ���� ���� ������ ��� ������ ���� ����  �� ����� �������� ����� ��� ������ ��������
	void shown_by_degree(int deg) {}//��� ���� ����� ���� ���� �������� 
	~Super_link_listed()//��� ����� ���� ��������� �� �������� 
	{
		//��� ���� ���� ���� ������� �� ������� ������� 
		Node* curr = first;
		while (curr != NULL) {
			first = curr->next;
			delete curr;
			curr = first;
		}
		//������� �� ���� ������ ��� ���� �� �������� ��� ��� �� ���� ��� ������� ��������� �� ����� �����  
	}
};

int main() {
	Super_link_listed newFile;
	string name, ad;
	float sala=0;
	 long long int num = 0;
	int  degree = 0;
	int Staff_n;
	cout << "Please enter the number of Staff:  "; cin >> Staff_n;
	while (Staff_n) {
		cin.ignore();
		cout << "Please enter the name of employee : "; getline(cin, name); 
		cout << "Plaese enter the employee's address : "; getline(cin, ad);
		cout << "Please enter the employee's phone number : "; cin >> num;
		cout << "Please enter the employee's degree : "; cin >> degree;
		cout << "Plese ener the employee's salary :"; cin >> sala;
		newFile.push_back(name, ad, sala,num, degree);
		system("CLS");
		Staff_n--;
	}
	int con = 1;
	while (con) {
		cout << "Please enter the number :\n 0)if you want to exit \n 1) if you want to show the staff \n 2)if you want to serch by name \n 3)if you want to show by degree :  "; cin >> con;
		if (con == 1) {
			system("CLS");
			newFile.output();
			system("pause");
		}
		else if (con == 2) {
			cin.ignore();
			system("CLS");
			cout << "Please Enter the Name :"; getline(cin, name);
			newFile.serch_by_name(name);
			system("pause");
		}
		else if (con == 3) {
			cout << "Please enter the degree : "; cin >> degree;
			newFile.shown_by_degree(degree);//��� ������ ���� :)
			system("pause");
		}
		system("CLS");
	}
}

// ����� ���� ��� ���� ����� �� ����� 