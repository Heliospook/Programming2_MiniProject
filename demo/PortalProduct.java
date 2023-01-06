package demo;

import ecomm.Globals;
import ecomm.Product;
import ecomm.Globals.Category;

import java.util.*;

public class PortalProduct extends Product{
    private String Name, ProductID;
    private float Price;
    private int Quantity;

    public PortalProduct(String[] line){
        this.Name = line[2];
        this.ProductID = line[3];
        this.Price = Float.parseFloat(line[4]);
        this.Quantity = Integer.parseInt(line[5]);
    }

    public Globals.Category getCategory(){ return Category.Book; }
	public String getName(){ return Name; }
	public String getProductID(){ return ProductID; }
	public float getPrice(){ return Price; }
	public int getQuantity(){ return Quantity;}

    @Override
    public String toString(){
        return Name  + " " + ProductID + " " + Price + " " + Quantity;
    }

    public static class ProductComp implements Comparator<PortalProduct>{
        private String parameter;
        public ProductComp(String parameter){
            this.parameter = parameter;
        }
        public int compare(PortalProduct a, PortalProduct b){
            if(parameter.equals("Name")){
                return a.getName().compareTo(b.getName());
            }else if(parameter.equals("Price")){
                float diff = a.getPrice() - b.getPrice();
                if(diff<0) return -1;
                else if(diff>0) return 1;
                else return 0;
            }
            return 0;
        }
    }
}
