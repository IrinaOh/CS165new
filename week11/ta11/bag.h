#ifndef BAG_H
#define BAG_H

#include <string>
/***********************************************************
 * Class: Bag
 * Description: Holds ints...for now
 ***********************************************************/
template <typename T>
class Bag
{
private:
   int capacity;
   int size;
   int currentAddIndex;
   T* data;

public:
   Bag()
   {
      capacity = 5;
      data = new T[capacity];
      currentAddIndex = 0;
   }

   ~Bag()
   {
      delete data;
   }
				
   // Getters
   int getCapacity()
   {
      return capacity;
   }

   int getCount()
   {
      return (currentAddIndex); 
   }

   T getItem(int index)
   {
      return data[index];
   }

   void addItem(T item)
   {
      if(currentAddIndex >= capacity)
      {
         T* data2 = new T[(capacity * 2)];
         
         for(int i = 0; i < capacity; i++)
         {
            data2[i] = data[i];
            
         }

         delete data;

         data = data2;

         capacity = (capacity * 2);
      }

      data[currentAddIndex] = item;
      currentAddIndex++;
   }

   int find(T item)
   {
      for(int i = 0; i <= currentAddIndex; i++)
      {
         if(data[i] == item)
         {
            return i;
         }
      }
      
      return -1;
   }

   void deleteItem(int index)
   {
      for(int i = index; i < currentAddIndex; i++)
      {
         data[i] = data[i+1];
      }

      currentAddIndex--;
   }
};

#endif

