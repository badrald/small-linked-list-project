//السلام عليكم هذا برنامح بيسط يقوم بإخذ ملف الموظفين و شرح بسيط لكيفة عمل ال link list خاصة بك 
#include<iostream>
#include<string>
using namespace std;
//هذه عقدة و لنعتبرها صندوق يحتوي على جميع العناصر التي نحتاجها
struct Node {
	string name, add;
	float  salary;
	long long int num_phone;
	int  degree;
	Node* next;
};
/*هنا الكلاس الذي من خلاله يمكننا جمع الصناديق و ربطها ببعظها البعض و تعديل عليها*/
class Super_link_listed {
	/*هنا نقوم بتحديد الصندوف الاول والاخير الذي يتحدد 
	فا لاننا لم نقم بوظع الصناديق فا علينا انعظيهم قيم فارغة  */
	Node* first=NULL;
	Node* last=NULL;
	int length = 0;//يحدد عدد الصناديق 
public:	
	//دالة لمعرفة اذا كان الهناك صناديق اما لا 
	int is_empty() {
		return length == 0;
	}
	/*هذه الدالة التي تقوم بإضافة الصناديق من الخلف و الذي بين الاقواس يحدد العناصر التي ستكون في الصندوق المضاف */
	void push_back(string n,string ad,float sal,long long int num,int deg) {
		Node* newNode = new Node;//نقوم بإنشاء صندوق جديد 
		newNode->name= n; newNode->add = ad; newNode->salary = sal; newNode->num_phone = num; newNode->degree = deg;//العناصر المظافة للصندوق الجديد
		//هنا نسأل اذا كان هناك صنديق من قبل ام لا 
		if (is_empty()) {
			//إذا لم يكن هناك صناديق من قبل فسيكون الصندوق المنشأ هو أول صندوق 
			first = last=newNode;//ولانه الصندوق الوحيد فسيكون اول و اخر صندوق 
			last->next = NULL;//وهنا نقوم بتجهيز لاستقبال الصناديق الاخرى 
			length++;
		}
		else {
			//هنا ان كان هناك صناديق من قبل فسيتم الاضافة الصندوق المنشأ من الجهة الخلفية 
			last->next = newNode;//بما أن الصندوق الاخير لا يوجد بعده صندوق فسنقوم بإضافة الصندوق المنشأ ونجعل الصندوق الاخير يأشر على الصندوق المنشأ 
			last = newNode;//هنا نجعل الصندوق الاخير هو الصندوق المنشأ 
			last->next = NULL;//هنا نهيئ الصندوق الاخير لأستقبال الصندوق اخر 
			length++;
		}

	}
	//دالة عرض التي تعرض ما بداخل الصناديق من اول صندوق تم ادخاله
	void output() {
		Node* curr = first;//هنا نقوم بإنشاء مؤشر ونقوم بوضعه على الصندوق الاول 
		while (curr != NULL) {
			cout << curr->name << "   " << curr->num_phone << "   " << curr->salary << "   " << curr->degree << "   " << curr->add<<endl;
			curr = curr->next;//هنا يقوم المؤشر بإنتقال الى الصندوق التالي 
		}
	}   
	//هذه الدالة تقوم بالبحث على على الموظف عن طريق اسمه
	void serch_by_name(string N){
		Node* curr = first;
		int conter = 1;
		while (curr != NULL){
			if (curr->name == N) {
				cout << "Found it at position :" << conter<<endl;//هنا اذا تم ايجاد الاسم وتقوم بالخروج 
				break;
			}
			conter++;
			curr = curr->next;
		}
		if (curr == NULL) {
			cout << "We don't find it :("<<endl;
		}
		
	}
	//اختبار نفسك بهذه المهمة هذه الدالة تقوم بعرض  ما بداخل الصناديق بناءً على الدرجة الوظيفية
	void shown_by_degree(int deg) {}//إذا اردت تلميح انظر اسفل البرنامج 
	~Super_link_listed()//هنا عندما نقوم بالانتهاء من البرنامج 
	{
		//هنا نقوم بحدف جميع العناصر من الذاكرة المؤقته 
		Node* curr = first;
		while (curr != NULL) {
			first = curr->next;
			delete curr;
			curr = first;
		}
		//بمانسبة لا انصح بإدخال عدد كبير من الموظفين لان ذلك قد يؤثر على الذاكرة العشوائية من ناحية الحجم  
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
			newFile.shown_by_degree(degree);//هذه المهمة صحيح :)
			system("pause");
		}
		system("CLS");
	}
}

// تلميح انظر الى دالة البحث عن الاسم 
