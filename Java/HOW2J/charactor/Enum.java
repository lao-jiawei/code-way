package charactor;

import java.util.Scanner;

//练习-枚举
public class Enum{
	public enum HeroType {
		TANK,WIZARD,ASSASSIN,ASSIST,WARRIOR,RANGED,PUSH,FARMING
	}
	public static void main(String[] args) {
		Scanner s = new Scanner(System.in);
//枚举遍历
//		for(HeroType ht: HeroType.values()) {
//			System.out.println(ht);
//		}
		System.out.println("请选择英雄类型：");
		System.out.println("TANK		(坦克)");
		System.out.println("WIZARD 		(法师)");
		System.out.println("ASSASSIN 	(刺客)");
		System.out.println("ASSIST 		(辅助)");
		System.out.println("WARRIOR 	(近战)");
		System.out.println("RANGED 		(远程)");
		System.out.println("PUSH 		(推进)");
		System.out.println("FARMING 	(打野)");
		System.out.println();
		System.out.print("请输入选择英雄类型（英文）：");
		String herotype = s.nextLine();
		System.out.print("你选择的英雄类型是：");
		switch(herotype) {
			case "TANK":
				System.out.println("坦克");
				break;
			case "WIZARD":
				System.out.println("法师");
				break;
			case "ASSASSIN":
				System.out.println("刺客");
				break;
			case "ASSIST":
				System.out.println("辅助");
				break;
			case "WARRIOR":
				System.out.println("近战");
				break;
			case "RANGED":
				System.out.println("远程");
				break;
			case "PUSH":
				System.out.println("推进");
				break;
			case "FARMING":
				System.out.println("打野");
				break;
			default:
				System.out.println("输入错误，请重新输入");
		}
	}
}
