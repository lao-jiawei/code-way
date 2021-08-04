package charactor;

import property.Weapon;

public class Hero {	//英雄
	
	private int id;
	public String name;	//姓名
	protected float hp;	//血量
	float maxHP;
	float armor;	//护甲
	int moveSpeed;	//移动速度
	
	int killNum;	//杀人次数
	int assistNum;	//助攻次数
	int secondPitNum; //补刀数
	
	int money;	//金钱
	
	String killspech;	//杀人后说的话
	String deadspech;	//被杀后说的话
	
	static String copyright;
	
	//物品栏的容量
	public static int itemCapacity = 8;	
	
	static {
		itemCapacity = 6;
	}

	
	public Hero(String name) {
		this.name = name;
	}
	
	public Hero(String name,float hp) {
		this(name);
		this.hp = hp;
	}
	
	public void die() {
		hp = 0;
	}
	
	public static void battleWin() {
		System.out.println("battle win");
	}
		
//练习-构造方法
//		public Hero(String heroName,float heroHP,float heroArmor,int heroMoveSpeed) {
//			name = heroName;
//			hp = heroHP;
//			armor = heroArmor;
//			moveSpeed = heroMoveSpeed;
//		}
		
//练习-构造方法（this）
		public Hero(String name,float hp,float armor,int moveSpeed) {
			this(name,hp);
			this.armor = armor;
			this.moveSpeed = moveSpeed;
		}
		
		//获得护甲值
		float getArmor() {
			return armor;
		}
		
		//坑队友
		void keng() {
			System.out.println("坑队友！");
		}
		
		//增加移动速度
		void addSpeed(int speed) {
			//在原来的基础上增加移动速度
			moveSpeed = moveSpeed + speed;
		}
		
		//超神
		void legendary() {
			System.out.println("超神");
		}
		
		//获取当前的血量
		float getHp() {
			return hp;
		}
		
		//回血
		void recovery(float blood) {
			hp = hp + blood; 
		}
		
		//装备一把武器
		public void equip(Weapon w) {
			
		}
		
//	public static void main(String[] args) {
//		Hero garen = new Hero("盖伦",616.28f,350,100);		
//		Hero teemo = new Hero("提莫",383f,14f,330);
//		
//		Hero.copyright = "版权由Riot Games公司所有";
//		
//		System.out.println(garen.name);
//		System.out.println(garen.copyright);
//		System.out.println();
//		
//		System.out.println(teemo.name);
//		System.out.println(teemo.copyright);
//		System.out.println();
//		 
//		garen.copyright = "Blizzard Entertainment Enterprise";
//		System.out.println(garen.name);
//		System.out.println(garen.copyright);
//		System.out.println();
//		
//		System.out.println(teemo.name);
//		System.out.println(teemo.copyright);
//		
//	}

//练习-单例模式（饿汉式）
		private Hero() {
			
		}
		
		private static Hero instance = new Hero();
		
		public static Hero getInstance() {
			return instance;
		}
}
