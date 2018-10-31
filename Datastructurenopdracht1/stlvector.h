//Auteurs:  Olivier Koster (s1826182)
//          Kousar Sedigi  (s1461907)
//Datum:    17-10-2018

#ifndef stlvector_h
#define stlvector_h

#include <vector>


template<typename T>
class Vector {

    std::vector<T> first;

  public:

    void create(); // maak een lege stapel
    bool isEmpty(); // bepaal of de stapel leeg is
    void clear(); // maak de stapel leeg
    bool push(T newItem); // voeg een newItem toe op de top van de stapel, en geef terug of de opdracht gelukt is
    bool pop(); // verwijder het bovenste element van de stapel, en geef terug of de opdracht gelukt is
    bool top(T &topItem); // geef het bovenste stapelelement, zonder dit te verwijderen, en geef terug of de opdracht gelukt is

  private:

};

template <typename T>
void Vector<T>::create() {

}

template <typename T>
bool Vector<T>::isEmpty() {
    if(first.empty()){

        return true;
    }
    else return false;

}//isEmpty

template <typename T>
bool Vector<T>::push(T newItem) {
    first.push_back(newItem);
    if (first.back() == newItem){

        return true;
    }
    else return false;

}//push

template <typename T>
bool Vector<T>::pop(){
    int size = first.size();
    first.pop_back();
    if(first.size() == size-1){
        return true;
    }
    else return false;

}//pop

template <typename T>
void Vector<T>::clear() {
    while (first.size() != 0){
        first.pop_back();

    }

}//clear

template <typename T>
bool Vector<T>::top(T &topItem) {
    topItem = first.back();
    if (topItem == first.back()){
        return true;
    }
    else return false;


}//top

#endif
