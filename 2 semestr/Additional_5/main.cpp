class Foo
{
public:
    Foo(int j) { i = new int[j]; }
    ~Foo() { delete i; } // �������� virtual
    //delete �������� �� delete[]
    //�������� ����������� � �������� �����������
private:  //�������� �� protected
    int* i;
};

// Foo �������� �� public Foo
class Bar : Foo
{
public:
    Bar(int j) { i = new char[j]; }// ��������  : Foo(j)
    ~Bar() { delete i; }// �������� virtual
    // delete �������� �� delete[]
private:  //�������� �� protected
    char* i;  //�������� �� int* i
};

void main() //void �������� �� int
{
    Foo* f = new Foo(100);
    Foo* b = new Bar(200);
    *f = *b;
    delete f;
    delete b;
}

