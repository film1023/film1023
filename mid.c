#include <stdio.h>
// สินค้ากลุ่ม "น้ำ"
#define PRICE_Cola              10   // TODO: แก้ตามโฟลว์ชาร์ต
#define PRICE_Green_juice       12   // TODO
#define PRICE_Americano         30   // TODO
#define PRICE_Latte             35   // TODO
// สินค้ากลุ่ม "ขนม"
#define PRICE_Sunflower_Seeds   13   // TODO
#define PRICE_Bean_Paep         20   // TODO
#define PRICE_Cin_Som_Hmk       15   // TODO
//จำนวนสินค้ากลุ่ม "น้ำ"
#define MAX_Cola                20
#define MAX_Green_juice         20
#define MAX_Americano           20
#define MAX_Latte               20
//จำนวนสินค้ากลุ่ม "ขนม"
#define MAX_Sunflower_Seeds     20
#define MAX_Bean_Paep           20
#define MAX_Cin_Som_Hmk         20
//จำนวนวันที่จะหมดอายุกลุ่ม "น้ำ"
#define EXP_Cola                30
#define EXP_Green_juice         30
#define EXP_Americano           15
#define EXP_Latte               30
//จำนวนวันที่จะหมดอายุกลุ่ม "ขนม"
#define EXP_Sunflower_Seeds     30
#define EXP_Bean_Paep           10
#define EXP_Cin_Som_Hmk         7
// จำนวนเงินที่เตรียมไว้ทอนในตู้
#define COIN1   50   // เหรียญ 1 บาท  50 เหรียญ
#define COIN2   50   // เหรียญ 2 บาท  50 เหรียญ
#define COIN5   50   // เหรียญ 5 บาท  50 เหรียญ
#define COIN10  50   // เหรียญ 10 บาท 50 เหรียญ
#define BANK20  20   // ธนบัตร 20  บาท 20 ใบ
#define BANK50  20   // ธนบัตร 50  บาท 20 ใบ
#define BANK100 50   // ธนบัตร 100 บาท 50 ใบ
#define BANK500  5   // ธนบัตร 500  บาท 5 ใบ
#define BANK1000 0   // ธนบัตร 1000 บาท 0 ใบ

// อ่านจำนวนแบบป้องกัน input เพี้ยนเล็กน้อย
int read_int_nonneg(const char *prompt) {
    int x;
    for (;;) {
        printf("%s", prompt);
        if (scanf("%d", &x) == 1 && x >= 0) return x;
        // ล้างบัฟเฟอร์
        int c;
        while ((c = getchar()) != '\n' && c != EOF) {}
        printf("** ใส่ตัวเลขจำนวนเต็มที่มากกว่าหรือเท่ากับ 0 เท่านั้นนะครับ **\n");
    }
}
// Start / กำหนดตัวแปรเริ
int main(void) {
    int a_totalItems = 0;     
    // จำนวนสินค้ารวม  (ตามโฟลว์ชาร์ต a = 0)
    double b_subtotal  = 0.0; 
    // ยอดรวมค่าสินค้า (ตามโฟลว์ชาร์ต b = 0)
    double c_grand     = 0.0; 
    // ยอดสุทธิหลังรวมค่าส่ง (ตามโฟลว์ชาร์ต c = 0)

    // นับแยกประเภทเผื่อใช้ (mapping จากเพชร “มีสินค้าหรือไม่ → เพิ่มตัวนับ”)
    int n_Cola = 0, n_Green_juice = 0, n_Americano = 0, n_Latte = 0;
    int n_Sunflower_Seeds = 0, n_Bean_Paep = 0, n_Cin_Som_Hmk = 0;

    // ==========================
    // เลือกประเภทสินค้า น้ำ / ขนม (loop จนกว่าจะเลิกเลือก)
    // ==========================
    for (;;) {
        int choiceType;
        printf("\n=== เลือกประเภทสินค้า ===\n");
        printf("1) น้ำ\n");
        printf("2) ขนม\n");
        printf("0) จบการเลือกและคำนวณยอด\n");
        printf("เลือก: ");
        if (scanf("%d", &choiceType) != 1) {
            int c; while ((c = getchar()) != '\n' && c != EOF) {}
            continue;
        }
        if (choiceType == 0) break;

        if (choiceType == 1) {
            // --------------------------
            // หมวด "น้ำ"
            // --------------------------
            for (;;) {
                int ch;
                printf("\n-- น้ำ --\n");
                printf("1) โค้ก           (ราคา %d)\n", PRICE_Cola);
                printf("2) น้ำเขียว         (ราคา %d)\n", PRICE_Green_juice);
                printf("3) อเมริกาโน่       (ราคา %d)\n", PRICE_Americano);
                printf("4) ลาเต้           (ราคา %d)\n", PRICE_Latte);
                printf("0) กลับไปเลือกประเภทสินค้า\n");
                printf("เลือก: ");
                if (scanf("%d", &ch) != 1) {
                    int c; while ((c = getchar()) != '\n' && c != EOF) {}
                    continue;
                }
                if (ch == 0) break;

                int qty = read_int_nonneg("   จำนวนที่ต้องการ: ");
                if (qty == 0) continue;

                switch (ch) {
                    case 1: n_Cola += qty; b_subtotal += qty * PRICE_Cola; break;
                    case 2: n_Green_juice        += qty; b_subtotal += qty * PRICE_Green_juice; break;
                    case 3: n_Americano      += qty; b_subtotal += qty * PRICE_Americano; break;
                    case 4: n_Latte     += qty; b_subtotal += qty * PRICE_Latte; break;
                    default: printf("เมนูไม่ถูกต้อง\n"); continue;
                }
                a_totalItems += qty; // อัปเดตตัวนับรวม (สอดคล้องเพชร “มีสินค้าหรือไม่ → +1”)
                printf("   เพิ่มสินค้าเรียบร้อย ✓\n");
            }
        } else if (choiceType == 2) {
            // --------------------------
            // หมวด "ขนม"
            // --------------------------
            for (;;) {
                int ch;
                printf("\n-- ขนม --\n");
                printf("1) แมลดทานตะวัน   (ราคา %d)\n", PRICE_Sunflower_Seeds);
                printf("2) ถั่วแปบ  (ราคา %d)\n", PRICE_Bean_Paep);
                printf("3) จิ้นส้มหมก  (ราคา %d)\n", PRICE_Cin_Som_Hmk);
                printf("0) กลับไปเลือกประเภทสินค้า\n");
                printf("เลือก: ");
                if (scanf("%d", &ch) != 1) {
                    int c; while ((c = getchar()) != '\n' && c != EOF) {}
                    continue;
                }
                if (ch == 0) break;

                int qty = read_int_nonneg("   จำนวนที่ต้องการ: ");
                if (qty == 0) continue;

                switch (ch) {
                    case 1: n_Sunflower_Seeds += qty; b_subtotal += qty * PRICE_Sunflower_Seeds;  break;
                    case 2: n_Bean_Paep += qty; b_subtotal += qty * PRICE_Bean_Paep; break;
                    case 3: n_Cin_Som_Hmk += qty; b_subtotal += qty * PRICE_Cin_Som_Hmk;  break;
                    default: printf("เมนูไม่ถูกต้อง\n"); continue;
                }
                a_totalItems += qty; // อัปเดตตัวนับรวม
                printf("   เพิ่มสินค้าเรียบร้อย ✓\n");
            }
        } else {
            printf("เมนูไม่ถูกต้อง\n");
        }
    }


// รวมยอดสินค้า → ยอดสุทธิ c
    if (a_totalItems > 0 && b_subtotal < 100) {
 
    }
    c_grand = b_subtotal;

    // ==========================
    // แสดงผลลัพธ์ (สอดคล้อง “สรุปยอด / จบการทำงาน”)
    // ==========================
    printf("\n================= ใบสรุปคำสั่งซื้อ =================\n");
    if (n_Cola) printf("โค้ก x %d = %d\n", n_Cola, n_Cola * PRICE_Cola);
    if (n_Green_juice) printf("น้ำเขียว    x %d = %d\n", n_Green_juice, n_Green_juice * PRICE_Green_juice);
    if (n_Americano) printf("อเมริกาโน่   x %d = %d\n", n_Americano, n_Americano * PRICE_Americano);
    if (n_Latte) printf("ลาเต้  x %d = %d\n", n_Latte,  n_Latte * PRICE_Latte);

    if (n_Sunflower_Seeds)      printf("แมลดทานตะวัน  x %d = %d\n", n_Sunflower_Seeds, n_Sunflower_Seeds * PRICE_Sunflower_Seeds);
    if (n_Bean_Paep)      printf("ถั่วแปบ x %d = %d\n", n_Bean_Paep, n_Bean_Paep * PRICE_Bean_Paep);
    if (n_Cin_Som_Hmk)      printf("จิ้นส้มหมก x %d = %d\n", n_Cin_Som_Hmk, n_Cin_Som_Hmk * PRICE_Cin_Som_Hmk);

    printf("-----------------------------------------------------\n");
    printf("จำนวนชิ้นรวม (a) : %d\n", a_totalItems);
    printf("ค่าสินค้ารวม (b) : %.2f\n", b_subtotal);
    printf("ยอดสุทธิ (c)     : %.2f\n", c_grand);
    printf("=====================================================\n");
    printf("ขอบคุณที่อุดหนุนครับ :)\n");
    return 0;
}
