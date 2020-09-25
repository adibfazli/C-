#ifndef  INVENTORY_H
#define INVENTORY_H
    class Inventory{
    private:
        int itemNumber , quantity;
        double cost , totalCost;
    public:
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
        void setItemNumber(int);
        void setQuantity(int);
        void setCost(double);
        void setTotalCost();
        int getItemNumber();
        int getQuantity();
        double getCost();
        double getTotalCost();
    };
#endif