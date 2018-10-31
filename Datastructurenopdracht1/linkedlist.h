//Auteurs:  Olivier Koster (s1826182)
//          Kousar Sedigi  (s1461907)
//Datum:    17-10-2018

#ifndef linkedlist_h
#define linkedlist_h


class vakje {

public:
    char letter;
    vakje* volgende;
    vakje(){
        char letter = '\0'; //waar de letter van de string wordt opgeslagen
        volgende = NULL;
    }
};

template <typename T>
class LinkedList{


public:

    void create(); // maak een lege stapel
    bool isEmpty(); // bepaal of de stapel leeg is
    void clear(); // maak de stapel leeg
    bool push(T newItem); // voeg een newItem toe op de top van de stapel, en geef terug of de opdracht gelukt is
    bool pop(); // verwijder het bovenste element van de stapel, en geef terug of de opdracht gelukt is
    bool top(T &topItem); // geef het bovenste stapelelement, zonder dit te verwijderen, en geef terug of de opdracht gelukt is

private:
    vakje* laatste;



};

template <typename T>
void LinkedList<T>::create() {

    laatste = NULL;
}

template <typename T>
bool LinkedList<T>::isEmpty() {
    if (laatste == NULL){
        return true;
    }//if
    else return false;
}//isEmpty


template <typename T>
bool LinkedList<T>::push(T newItem) {
    vakje* temp = new vakje;
    temp->letter = newItem;
    temp->volgende = laatste;
    laatste = temp;
    return true;
}//push

template <typename T>
bool LinkedList<T>::pop(){
    if (isEmpty())
      return false;
    vakje* temp = laatste;
    laatste = laatste->volgende;
    delete temp;
    return true;
}//pop

template <typename T>
void LinkedList<T>::clear() {
    while ( ! isEmpty() ){
        pop();
    }
}//clear

template <typename T>
bool LinkedList<T>::top(T &topItem) {
    if (isEmpty())
      return false;
    topItem = laatste->letter;
    return true;
}//top


#endif
