package JAVA基础;



public class Item {
	private String name;
	private int price;
	public Item(String objName,int objprice) 
	{
		name=objName;
		price=objprice;
	}
	
	public static void main(String[] args) {
		Item bloodBottle =new Item("血瓶",50);
		Item item2=new Item("草鞋",300);
		Item item3=new Item("长剑",350);
		
		System.out.println("名称\t价格");
		System.out.println(bloodBottle.name+"\t"+bloodBottle.price);
		System.out.println(item2.name+"\t"+item2.price);
		System.out.println(item3.name+"\t"+item3.price);
		}
}
