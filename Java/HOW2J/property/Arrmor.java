package property;

//练习-护甲
public class Arrmor extends Item{	//护甲
	int ac;	//护甲等级
	public static void main(String[] args) {
		Arrmor cloth = new Arrmor();
		Arrmor hauberk = new Arrmor();
		
		cloth.name = "布甲";
		cloth.price = 300;
		cloth.ac = 15;
		
		hauberk.name = "锁子甲";
		hauberk.price = 500;
		hauberk.ac = 40;
	}
}
