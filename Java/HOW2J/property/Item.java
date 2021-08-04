package property;



public class Item {	//物品
	protected String name;
	protected int price;
//练习-单例模式（懒汉式）
	private Item() {
		
	}
	private static Item instance;
	
	public static Item getInstance() {
		if(null==instance) {
			instance = new Item();
		}
		return instance;
	}
}
