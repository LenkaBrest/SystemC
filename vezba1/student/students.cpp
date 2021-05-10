#include <vector>
#include <iostream>
#include <algorithm>
#include <fstream>

using namespace std;

class Student
{
	private:
		string name;
		int points;
		int index;
	
	public:
		Student(const string& name="", const int points=0, const int index=0):
		name(name), points(points), index(index) {}
		
		string get_name() const {return name;}
		int get_points() const {return points;}
		int get_index() const {return index;}
		
		void set_name(const string& name) {this->name = name;}
		void set_points(const int points) {this->points = points;}
		void set_index(const int index) {this->index = index;}
		
		friend bool bigger (const Student&, const Student&);
		
		friend ostream& operator << (ostream&, const Student&);
		
};

bool bigger (const Student& s1, const Student& s2)
{
	if(s1.points != s2.points)
	{
		return s1.points>s2.points;
	}
	else
	{
		return s1.index>s2.index;
	}
}

ostream& operator << (ostream& out, const Student& s)
{
	out<<"Name: "<<s.name<<" points: "<<s.points<<" index: "<<s.index;
	return out;
}

void input_students(vector<Student>& s)
{
	string name;
	int points;
	int index;
	ifstream file;
	file.open("students.txt");
	if(file.is_open())
		while(!file.eof())
		{
			file >> name >> points >> index;
			s.push_back(Student(name,points,index));
		}
}

void print_students(vector<Student>& s)
{
	vector<Student>::iterator it;
	
	for(it = s.begin(); it!=s.end(); ++it)
		cout<<*it<<endl;
}


int main()
{
	vector<Student> st;

	input_students(st);
	
	print_students(st);
	
	sort(st.begin(), st.end(), bigger);
	
	print_students(st);
	
	return 0;
}
	
