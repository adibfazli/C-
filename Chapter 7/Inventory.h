#ifndef  INVENTORY_H
#define INVENTORY_H
class Inventory{
    // private members of the class
    private:
        int itemNumber , quantity;
        double cost , totalCost;
    // public members of the class
    public:
        // constructor , and by default setting the values to 0
        Inventory(){
            itemNumber = quantity = 0;
            cost = totalCost = 0.0;
        }
        Inventory( int itemNumber, double cost, int quantity){
            setItemNumber(itemNumber); 
            setCost(cost);             
            setQuantity(quantity);     
            setTotalCost();            
        }
        //     setter functions
        void setItemNumber(int); // setter function which sets the (ITEM NUMBER) value in the class.
        void setQuantity(int);   // setter function which sets the (QUANTITY) value in the class.
        void setCost(double);    // setter function which sets the (COST) value in the class.
        void setTotalCost();     // setter function which sets the (TOTAL COST) value in the class.
        //     getter functions
        int getItemNumber();   // getter function which gets the (ITEM NUMBER) value in the class.
        int getQuantity();     // getter function which gets the (QUANTITY) value in the class.
        double getCost();      // getter function which gets the (COST) value in the class.
        double getTotalCost(); // getter function which gets the (TOTAL COST) value in the class.
};
#endif