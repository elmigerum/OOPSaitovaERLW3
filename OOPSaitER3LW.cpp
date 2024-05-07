#include <iostream>
#include <ctime>

class Figure {
public:
    virtual void numofAngles() {
        printf("У фигур может быть различное количество углов\n");
    }
};

class Triangle : public Figure {
public:
    virtual void numofAngles() override {
        printf("У треугольника три угла\n");
    }
};

class Rectangle : public Figure {
public:
    virtual void numofAngles() override {
        printf("У четырехугольника четыре угла\n");
    }
};

class Pentagon : public Figure {
public:
    virtual void numofAngles() override {
        printf("У пятиугольника пять углов\n");
    }
};


template<class T>
class Array {
private:
    T *elems;
    int size;
    int capacity;

public:
    Array() : size(0), capacity(1) {
        elems = new T[capacity];
    }

    virtual ~Array() {
        delete[] elems;
    }

    int getSize() const {
        return size;
    }

    int getCapacity() const {
        return capacity;
    }

    T getElem(int n) {
        return elems[n];
    }

    void addbeg(T elem) {
        if (size == capacity) {
            expandcapacity();
        }
        size += 1;
        if (size > 0) {
            for (int i = size - 1; i > 0; i--) {
                elems[i] = elems[i - 1];
            }
        }
        elems[0] = elem;
    }

    void addend(T elem) {
        if (size == capacity) {
            expandcapacity();
        }
        elems[size] = elem;
        size += 1;
    }

    void insert(T elem, int n) {
        if (n >= size) {
            printf("Ошибка: индекс вставки больше или равен размеру массива\n");
            return;
        }

        if (size == capacity) {
            expandcapacity();
        }
        size += 1;
        for (int i = size - 1; i > n; i--) {
            elems[i] = elems[i - 1];
        }
        elems[n] = elem;
    }

    T takeElem(int n) {
        if (size == 0) {
            printf("Контейнер пустой: объектов для удаления нет\n");
            return nullptr;
        } else {
            T x = elems[n];
            size -= 1;
            for (int i = n; i < size; i++) {
                elems[i] = elems[i + 1];
            }
            return x;
        }
    }


    void setElem(int n, T elem) {
        elems[n] = elem;
    }

private:
    void expandcapacity() {
        int newCapacity = capacity * 2;
        T *newElems = new T[newCapacity];
        for (int i = 0; i < size; i++) {
            newElems[i] = elems[i];
        }
        delete[] elems;
        elems = newElems;
        capacity = newCapacity;
    }
};


int main() {
    Array<Figure *> shapes;
    for (int i = 0; i < 5; i++) {
        if (i < 5) {
            shapes.addend(new Triangle());
        } else {
            shapes.addend(new Rectangle());
        }
    }

    for (int i = 0; i < shapes.getSize(); i++) {
        shapes.getElem(i)->numofAngles();
    }

    printf("\n\n");

    shapes.takeElem(0);

    for (int i = 0; i < shapes.getSize(); i++) {
        shapes.getElem(i)->numofAngles();
    }

    printf("\n\n");


    shapes.takeElem(0);

    for (int i = 0; i < shapes.getSize(); i++) {
        shapes.getElem(i)->numofAngles();
    }

    printf("\n\n");

    shapes.addend(new Pentagon());

    for (int i = 0; i < shapes.getSize(); i++) {
        shapes.getElem(i)->numofAngles();
    }

    printf("\n\n");


    shapes.addbeg(new Triangle());

    for (int i = 0; i < shapes.getSize(); i++) {
        shapes.getElem(i)->numofAngles();
    }

    printf("\n\n");


    shapes.insert(new Pentagon(), 7);

    for (int i = 0; i < shapes.getSize(); i++) {
        shapes.getElem(i)->numofAngles();
    }

    printf("\n\n");

    shapes.setElem(2, new Rectangle());
    for (int i = 0; i < shapes.getSize(); i++) {
        shapes.getElem(i)->numofAngles();
    }

    printf("\n\n");


    printf("%d %d", shapes.getCapacity(), shapes.getSize());


    printf("\n\n");

// цикл из 100 случ-х действий:
    clock_t startTime = clock();

    for (int i = 0; i<100;i++){
        int action  = rand() % 5;
        int index = rand() % shapes.getSize();
        Figure * figure;

        int random_object = rand()%3;
        if (random_object % 3 == 0) {
            figure = new Rectangle();
        }
        else if (random_object % 3 == 1) {
            figure = new Triangle();
        }
        else {
            figure = new Pentagon();
        }

        switch (action) {
            case 0:
                shapes.setElem(index, figure);
                break;
            case 1:
                shapes.insert( figure, index);
                break;
            case 2:
                shapes.addend(figure);
                break;
            case 3:
                shapes.addbeg(figure);
                break;
            case 4:
                shapes.takeElem(index);
                break;
        }
    }

    clock_t endTime = clock();
    for (int i = 0; i < shapes.getSize(); i++) {
        shapes.getElem(i)->numofAngles();
    }


    double seconds = (double)(endTime - startTime) / CLOCKS_PER_SEC;
    printf("The time : %f seconds - 100 actions\n", seconds);


// цикл из 1000 случ-х действий:
    clock_t startTime10 = clock();

    for (int i = 0; i<1000;i++){
        int action  = rand() % 5;
        int index = rand() % shapes.getSize();
        Figure * figure;

        int random_object = rand()%3;
        if (random_object % 3 == 0) {
            figure = new Rectangle();
        }
        else if (random_object % 3 == 1) {
            figure = new Triangle();
        }
        else {
            figure = new Pentagon();
        }


        switch (action) {
            case 0:
                shapes.setElem(index, new Rectangle);
                break;
            case 1:
                shapes.insert( new Triangle, index);
                break;
            case 2:
                shapes.addend(new Rectangle);
                break;
            case 3:
                shapes.addbeg(new Rectangle);
                break;
            case 4:
                shapes.takeElem(index);
                break;
        }
    }

    clock_t endTime10 = clock();
    /*for (int i = 0; i < shapes.getSize(); i++) {
        shapes.getElem(i)->numofAngles();
    }*/

    double seconds10 = (double)(endTime10 - startTime10) / CLOCKS_PER_SEC;
    printf("The time : %f seconds - 1000 actions\n", seconds10);

// цикл из 10000 случ-х действий:
    clock_t startTime100 = clock();

    for (int i = 0; i<10000;i++){
        int action  = rand() % 5;
        int index = rand() % shapes.getSize();
        Figure * figure;

        int random_object = rand()%3;
        if (random_object % 3 == 0) {
            figure = new Rectangle();
        }
        else if (random_object % 3 == 1) {
            figure = new Triangle();
        }
        else {
            figure = new Pentagon();
        }


        switch (action) {
            case 0:
                shapes.setElem(index, new Rectangle);
                break;
            case 1:
                shapes.insert( new Triangle, index);
                break;
            case 2:
                shapes.addend(new Rectangle);
                break;
            case 3:
                shapes.addbeg(new Rectangle);
                break;
            case 4:
                shapes.takeElem(index);
                break;
        }
    }

    clock_t endTime100 = clock();

    /*for (int i = 0; i < shapes.getSize(); i++) {
        shapes.getElem(i)->numofAngles();
    }*/

    double seconds100 = (double)(endTime100 - startTime100) / CLOCKS_PER_SEC;
    printf("The time : %f seconds - 10000 actions\n", seconds100);

    return 0;
}
