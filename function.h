struct node {
  int bnumber; // bicycle number
  int studentid;
  int day, month, year;
  struct node *next;
} * head, *var, *pWalker;

struct use {
  int per[10];
} used;

  
int insert(int studentid, int bikenumber, int day, int month, int year) 
{  
  struct node *temp; //pointerofstruct
  temp = (struct node *)malloc(sizeof(struct node));
  temp->studentid = studentid;
  temp->bnumber = bikenumber;
  temp->day = day;
  temp->month = month;
  temp->year = year;

  //เช็คว่าคนจองซ้ำไหม (หัวอ่าน)
  struct node *TEMP;
  TEMP = head;
  while (TEMP != NULL) //ลูปตั้งแต่หัวโหนดเพื่อเช็ค
  {
    if (TEMP->studentid == temp->studentid) 
    {
      return (0);
    }
    TEMP = TEMP->next;
  }

  if (head == NULL) // connect
  {
    head = temp;
    head->next = NULL;
  } else {
    temp->next = head;
    head = temp;
  }
  
  used.per[bikenumber - 1] = used.per[bikenumber - 1] - 25; // used.per[0] คือของคันที่ 1 ให้ = -25 ต่อการยืม 1 ครั้ง
  return (1);
}

   //parameter ลบ 4 ตัวแปร
{
  struct node *temp;
  struct node *prev; //ก่อนหน้านี้

  temp = head;
  while (temp != NULL) //loop all node
  {
    if (temp->studentid == studentid) 
    {
      if (datetoday(d, m, y) < datetoday(temp->day, temp->month, temp->year))
      { //ถ้าตัวที่ป้อนเข้ามาค่าไม่ตรงกับที่ไว้
        printf("\n========================\nYou entered an invalid "
               "date.\n========================\n"); //ใส่เวลาผิด
        break;
      } else {
        if (datetoday(d, m, y) - datetoday(temp->day, temp->month, temp->year) >
            7) //ถ้า dateday เกิน 7 วัน วันปรับวันละ 10 บาท แพงเกิ้น
        {
          if (datetoday(d, m, y) -
                  datetoday(temp->day, temp->month, temp->year) >
              30) //เกิน 30 วันปรับ 500 บาท
          {
            printf("\nYou have been fined 500 baht.\nPlease contact the staff "
                   "to pay.\n");
          } else {
            printf("\nYou have been fined %d baht.\nPlease contact the staff "
                   "to pay.\n",
                   (datetoday(d, m, y) -
                    datetoday(temp->day, temp->month, temp->year) )*
                       10);
          }
        }
        printf("\n========================");
        printf("\nSuccessfully returned a bike.\n");
        printf("========================\n");
        if (head == temp) {
          head = temp->next;
          free(temp);
          break;
        } else {
          prev->next = temp->next; //ตัวก่อนหน้ากลับไปชี้ next แล้ว temp ก็กลับไปชี้ next
          free(temp); //ฆ่่า temp ทิ้ง
          break;
        }
      }
    }
    prev = temp;
    temp = temp->next;
  }
  if (temp == NULL) { //กรณีลบแล้วไม่มีโหนดอะไร
    printf("\n========================");
    printf("\nYou did't booking a bike\n");
    printf("========================\n");
  }
}

void display() {
  pWalker = head; //pwalker เหมือนหัวอ่าน
  if (pWalker == NULL) {
    printf("\n========================\nNot have any booking yet. "
           "\n========================\n");
  } else {
    while (pWalker != NULL) {
      printf("[studentID -> %d ]\n", pWalker->studentid);
      printf("[Bike Number-> %d ]\n", pWalker->bnumber);
      printf("[Bike Percent from 100% -> %d% ]\n", used.per[pWalker->bnumber - 1]);
      printf("===============================\n");
      pWalker = pWalker->next;
    }
  }
}

int datetoday(int d, int m, int y) {
  int day;
  switch (m) {
  case 1:
    day = d + (0) + y * 365;
    break;
  case 2:
    day = d + (31) + y * 365;
    break;
  case 3:
    day = d + (31 + 29) + y * 365;
    break;
  case 4:
    day = d + (31 + 29 + 31) + y * 365;
    break;
  case 5:
    day = d + (31 + 29 + 31 + 30) + y * 365;
    break;
  case 6:
    day = d + (31 + 29 + 31 + 30 + 31) + y * 365;
    break;
  case 7:
    day = d + (31 + 29 + 31 + 30 + 31 + 30) + y * 365;
    break;
  case 8:
    day = d + (31 + 29 + 31 + 30 + 31 + 30 + 31) + y * 365;
    break;
  case 9:
    day = d + (31 + 29 + 31 + 30 + 31 + 30 + 31 + 31) + y * 365;
    break;
  case 10:
    day = d + (31 + 29 + 31 + 30 + 31 + 30 + 31 + 31 + 30) + y * 365;
    break;
  case 11:
    day = d + (31 + 29 + 31 + 30 + 31 + 30 + 31 + 31 + 30 + 31) + y * 365;
    break;
  case 12:
    day = d + (31 + 29 + 31 + 30 + 31 + 30 + 31 + 31 + 30 + 31 + 30) + y * 365;
    break;
  }
  return day;
}

int checkdate(int d, int m, int y) {
  if (y < 2022 || y > 2025)
  {
    return 0;
  }
  switch (m) {
  case 1:
    if (d > 31 || d < 1)
      return 0;
    else
      return 1;
    break;
  case 2:
    if (d > 29 || d < 1)
      return 0;
    else
      return 1;
    break;
  case 3:
    if (d > 31 || d < 1)
      return 0;
    else
      return 1;
    break;
  case 4:
    if (d > 30 || d < 1)
      return 0;
    else
      return 1;
    break;
  case 5:
    if (d > 31 || d < 1)
      return 0;
    else
      return 1;
    break;
  case 6:
    if (d > 30 || d < 1)
      return 0;
    else
      return 1;
    break;
  case 7:
    if (d > 31 || d < 1)
      return 0;
    else
      return 1;
    break;
  case 8:
    if (d > 31 || d < 1)
      return 0;
    else
      return 1;
    break;
  case 9:
    if (d > 30 || d < 1)
      return 0;
    else
      return 1;
    break;
  case 10:
    if (d > 31 || d < 1)
      return 0;
    else
      return 1;
    break;
  case 11:
    if (d > 30 || d < 1)
      return 0;
    else
      return 1;
    break;
  case 12:
    if (d > 31 || d < 1)
      return 0;
    else
      return 1;
    break;
  default:
    return 0;
    break;
  }
  return 0;
}

void assignuse() {
  int i;
  int *a;
  a = &used.per;
  for (i = 0; i < 10; i++) {
    *a = 100;
    a++;
  }
}

int sort(void) // sort percent การใช้จักก้า
{
  struct node *temp;
  temp = head;
  int count = 0, i, j, k = 0, tem = 0, check;
  int bnum[10 - count], perused[10 - count];

  while (temp != NULL) {
    temp = temp->next;
    count++; // นับคันที่อยู่ใน linked list(กำลังถูกเช่า)
  }

  if (count == 10) //รถเช่าหมดแล้ว
  {
    return 0;
  }

  if (count != 0) { // มีคันที่ถูกเช่า
    int beingrent[count];
    temp = head;
    while (temp != NULL) {
      beingrent[k] = temp->bnumber;
      temp = temp->next;
      k++;
    }
    k = 0;

    for (i = 0; i < 10; i++) {
      check = 0;
      for (j = 0; j < count; j++) {
        if ((i + 1) == beingrent[j]) { // กรองว่าตัวไหนไม่ถูกเช่า
          check++;
        }
      }
      if (check == 0) {
        bnum[k] = i + 1;
      } else {
        k--;
      }
      k++;
    }
  } else { // count=0 ไม่มีคันที่ถูกเช่า ไม่สร้าง beingrent
    for (i = 0; i < 10; i++) {
      bnum[i] = i + 1;
    }
  }

  for (i = 0; i < 10 - count; i++) {
    perused[i] = used.per[bnum[i] - 1]; // แก้ตรงนี้เป็น bnum[i]-1
    //printf("Long Check Doo Len Len\n");
    //printf("Bike No.%d can use \n", bnum[i]); //ลองสร้างเช็คดูเฉยๆ
  }
  tem = selection(perused, bnum, 10 - count);
  if (used.per[tem - 1] <= 0) //ถ้าused.per น้อยกว่าเท่ากับ 0 บอกว่าจักรยานหมด
  {
    return 0;
  }
  return tem;
}

int selection(int x[], int y[],
              int n) // n ส่งค่า count เพื่อ sort //x รับค่า used.per เข้ามา
{
  int max, i, imax, j, t;

  for (j = 0; j < n - 1; j++) {
    // max=x[j];
    imax = j;
    for (i = j + 1; i < n; i++) {
      if (x[i] > x[imax]) {
        // max = x[i];
        imax = i;
      }
    }
    swap(&x[j], &x[imax]);
    swap(&y[j], &y[imax]);
  }
  return y[0];
}

void swap(int *x, int *y) {
  int t;
  t = *x;
  *x = (*y);
  (*y) = t;
}

void return_menu(void) {
  int Enter = 1;
  while (Enter != 0) {
    printf("\n\nEnter 0 to return to the menu.\n");
    scanf("%d", &Enter);
  }
  system("clear");
}
