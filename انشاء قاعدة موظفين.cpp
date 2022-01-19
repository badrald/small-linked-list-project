//ÇáÓáÇã Úáíßã åĞÇ ÈÑäÇãÍ ÈíÓØ íŞæã ÈÅÎĞ ãáİ ÇáãæÙİíä æ ÔÑÍ ÈÓíØ áßíİÉ Úãá Çá link list ÎÇÕÉ Èß 
#include<iostream>
#include<string>
using namespace std;
//åĞå ÚŞÏÉ æ áäÚÊÈÑåÇ ÕäÏæŞ íÍÊæí Úáì ÌãíÚ ÇáÚäÇÕÑ ÇáÊí äÍÊÇÌåÇ
struct Node {
	string name, add;
	float  salary;
	long long int num_phone;
	int  degree;
	Node* next;
};
/*åäÇ ÇáßáÇÓ ÇáĞí ãä ÎáÇáå íãßääÇ ÌãÚ ÇáÕäÏÇíŞ æ ÑÈØåÇ ÈÈÚÙåÇ ÇáÈÚÖ æ ÊÚÏíá ÚáíåÇ*/
class Super_link_listed {
	/*åäÇ äŞæã ÈÊÍÏíÏ ÇáÕäÏæİ ÇáÇæá æÇáÇÎíÑ ÇáĞí íÊÍÏÏ 
	İÇ áÇääÇ áã äŞã ÈæÙÚ ÇáÕäÇÏíŞ İÇ ÚáíäÇ ÇäÚÙíåã Şíã İÇÑÛÉ  */
	Node* first=NULL;
	Node* last=NULL;
	int length = 0;//íÍÏÏ ÚÏÏ ÇáÕäÇÏíŞ 
public:	
	//ÏÇáÉ áãÚÑİÉ ÇĞÇ ßÇä ÇáåäÇß ÕäÇÏíŞ ÇãÇ áÇ 
	int is_empty() {
		return length == 0;
	}
	/*åĞå ÇáÏÇáÉ ÇáÊí ÊŞæã ÈÅÖÇİÉ ÇáÕäÇÏíŞ ãä ÇáÎáİ æ ÇáĞí Èíä ÇáÇŞæÇÓ íÍÏÏ ÇáÚäÇÕÑ ÇáÊí ÓÊßæä İí ÇáÕäÏæŞ ÇáãÖÇİ */
	void push_back(string n,string ad,float sal,long long int num,int deg) {
		Node* newNode = new Node;//äŞæã ÈÅäÔÇÁ ÕäÏæŞ ÌÏíÏ 
		newNode->name= n; newNode->add = ad; newNode->salary = sal; newNode->num_phone = num; newNode->degree = deg;//ÇáÚäÇÕÑ ÇáãÙÇİÉ ááÕäÏæŞ ÇáÌÏíÏ
		//åäÇ äÓÃá ÇĞÇ ßÇä åäÇß ÕäÏíŞ ãä ŞÈá Çã áÇ 
		if (is_empty()) {
			//ÅĞÇ áã íßä åäÇß ÕäÇÏíŞ ãä ŞÈá İÓíßæä ÇáÕäÏæŞ ÇáãäÔÃ åæ Ãæá ÕäÏæŞ 
			first = last=newNode;//æáÇäå ÇáÕäÏæŞ ÇáæÍíÏ İÓíßæä Çæá æ ÇÎÑ ÕäÏæŞ 
			last->next = NULL;//æåäÇ äŞæã ÈÊÌåíÒ áÇÓÊŞÈÇá ÇáÕäÇÏíŞ ÇáÇÎÑì 
			length++;
		}
		else {
			//åäÇ Çä ßÇä åäÇß ÕäÇÏíŞ ãä ŞÈá İÓíÊã ÇáÇÖÇİÉ ÇáÕäÏæŞ ÇáãäÔÃ ãä ÇáÌåÉ ÇáÎáİíÉ 
			last->next = newNode;//ÈãÇ Ãä ÇáÕäÏæŞ ÇáÇÎíÑ áÇ íæÌÏ ÈÚÏå ÕäÏæŞ İÓäŞæã ÈÅÖÇİÉ ÇáÕäÏæŞ ÇáãäÔÃ æäÌÚá ÇáÕäÏæŞ ÇáÇÎíÑ íÃÔÑ Úáì ÇáÕäÏæŞ ÇáãäÔÃ 
			last = newNode;//åäÇ äÌÚá ÇáÕäÏæŞ ÇáÇÎíÑ åæ ÇáÕäÏæŞ ÇáãäÔÃ 
			last->next = NULL;//åäÇ äåíÆ ÇáÕäÏæŞ ÇáÇÎíÑ áÃÓÊŞÈÇá ÇáÕäÏæŞ ÇÎÑ 
			length++;
		}

	}
	//ÏÇáÉ ÚÑÖ ÇáÊí ÊÚÑÖ ãÇ ÈÏÇÎá ÇáÕäÇÏíŞ ãä Çæá ÕäÏæŞ Êã ÇÏÎÇáå
	void output() {
		Node* curr = first;//åäÇ äŞæã ÈÅäÔÇÁ ãÄÔÑ æäŞæã ÈæÖÚå Úáì ÇáÕäÏæŞ ÇáÇæá 
		while (curr != NULL) {
			cout << curr->name << "   " << curr->num_phone << "   " << curr->salary << "   " << curr->degree << "   " << curr->add<<endl;
			curr = curr->next;//åäÇ íŞæã ÇáãÄÔÑ ÈÅäÊŞÇá Çáì ÇáÕäÏæŞ ÇáÊÇáí 
		}
	}   
	//åĞå ÇáÏÇáÉ ÊŞæã ÈÇáÈÍË Úáì Úáì ÇáãæÙİ Úä ØÑíŞ ÇÓãå
	void serch_by_name(string N){
		Node* curr = first;
		int conter = 1;
		while (curr != NULL){
			if (curr->name == N) {
				cout << "Found it at position :" << conter<<endl;//åäÇ ÇĞÇ Êã ÇíÌÇÏ ÇáÇÓã æÊŞæã ÈÇáÎÑæÌ 
				break;
			}
			conter++;
			curr = curr->next;
		}
		if (curr == NULL) {
			cout << "We don't find it :("<<endl;
		}
		
	}
	//ÇÎÊÈÇÑ äİÓß ÈåĞå ÇáãåãÉ åĞå ÇáÏÇáÉ ÊŞæã ÈÚÑÖ  ãÇ ÈÏÇÎá ÇáÕäÇÏíŞ ÈäÇÁğ Úáì ÇáÏÑÌÉ ÇáæÙíİíÉ
	void shown_by_degree(int deg) {}//ÅĞÇ ÇÑÏÊ ÊáãíÍ ÇäÙÑ ÇÓİá ÇáÈÑäÇãÌ 
	~Super_link_listed()//åäÇ ÚäÏãÇ äŞæã ÈÇáÇäÊåÇÁ ãä ÇáÈÑäÇãÌ 
	{
		//åäÇ äŞæã ÈÍÏİ ÌãíÚ ÇáÚäÇÕÑ ãä ÇáĞÇßÑÉ ÇáãÄŞÊå 
		Node* curr = first;
		while (curr != NULL) {
			first = curr->next;
			delete curr;
			curr = first;
		}
		//ÈãÇäÓÈÉ áÇ ÇäÕÍ ÈÅÏÎÇá ÚÏÏ ßÈíÑ ãä ÇáãæÙİíä áÇä Ğáß ŞÏ íÄËÑ Úáì ÇáĞÇßÑÉ ÇáÚÔæÇÆíÉ ãä äÇÍíÉ ÇáÍÌã  
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
			newFile.shown_by_degree(degree);//åĞå ÇáãåãÉ ÕÍíÍ :)
			system("pause");
		}
		system("CLS");
	}
}

// ÊáãíÍ ÇäÙÑ Çáì ÏÇáÉ ÇáÈÍË Úä ÇáÇÓã 