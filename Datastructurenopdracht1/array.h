//Auteurs:  Olivier Koster (s1826182)
//          Kousar Sedigi  (s1461907)
//Datum:    17-10-2018

#ifndef array_h
#define array_h

int MAX = 100;

template <typename T>
class Array{

  public:
    void create(); // maak een lege stapel
    bool isEmpty(); // bepaal of de stapel leeg is
    void clear(); // maak de stapel leeg
    bool push(T newItem); // voeg een newItem toe op de top van de stapel, en geef terug of de opdracht gelukt is
    bool pop(); // verwijder het bovenste element van de stapel, en geef terug of de opdracht gelukt is
    bool top(T &topItem); // geef het bovenste stapelelement, zonder dit te verwijderen, en geef terug of de opdracht gelukt is

  private:
    T A[100];
    int lengte;

};//Class Array

    template <typename T>
    void Array<T>::create() {
      lengte = -1;
      for (int i=0; i <= MAX-1; i++) {
        A[i] = '\0';
      }
    }//create

    template <typename T>
    bool Array<T>::isEmpty() {
          if (lengte == -1){
            return true;
          }//if
          else return false;
    }//isEmpty

    template <typename T>
    void Array<T>::clear(/* arguments */) {
      for (int i=-1; i <= lengte; i++) {
        A[i] = '\0';
      }//for
    }//clear

    template <typename T>
    bool Array<T>::push(T newItem) {
      lengte++;
      A[lengte] = newItem;
      if (A[lengte]==newItem) {
        return true;
      }//if
      else return false;
    }//push

    template <typename T>
    bool Array<T>::pop(){
      if (isEmpty())
        return false;
      A[lengte] = '\0';
      lengte--;
      return true;
    }//pop

    template <typename T>
    bool Array<T>::top(T &topItem) {
      topItem = A[lengte];
      if (topItem == A[lengte]){
        return true;
      }
      else return false;
    }//top

#endif
