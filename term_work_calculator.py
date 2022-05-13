def iotl():
  print("\n###### Internet Of Things Laborartory #####")
  iot_conducted=int(input("\nNumber of practical session conducted: "))
  iot_attended=int(input("\nNumber of practical session attended: "))
  iot_attendence=(iot_attended/iot_conducted)*50

  print("\nEnter appropriate marks according to the performance: ")
  print("\nFor Excellent/On time - 50 , Average/Late - 35 , Satisfactory/Very Late - 20 ")
  writeups=int(input("\nEnter a marks for writeup submission: "))
  practical_performed=int(input("\nEnter a marks for practicals performed: "))
  project=int(input("\nEnter a marks for project work: "))
  mock=int(input("\nEnter a marks for mock exams: "))
  
  iot_tw=(iot_attendence+writeups+practical_performed+project+mock)/5

  print("\nTerm work for IOT lab: ",iot_tw)

def dsal():
  print("\n###### Data Structure & Algorithms Laborartory #####")
  dsa_conducted=int(input("\nNumber of practical session conducted: "))
  dsa_attended=int(input("\nNumber of practical session attended: "))
  dsa_attendence=(dsa_attended/dsa_conducted)*50

  print("\nEnter appropriate marks according to the performance: ")
  print("\nFor Excellent/On time - 50 , Average/Late - 35 , Satisfactory/Very Late - 20 ")
  writeups=int(input("\nEnter a marks for writeup submission: "))
  practical_performed=int(input("\nEnter a marks for practicals performed: "))
  project=int(input("\nEnter a marks for project work: "))
  mock=int(input("\nEnter a marks for mock exams: "))
  
  dsa_tw=(dsa_attendence+writeups+practical_performed+project+mock)/5
  dsa_tw=dsa_tw/2

  print("\nTerm work for DSA lab: ",dsa_tw)

def pbl():
  print("\n###### Project Based Learning #####")
  pbl_conducted=int(input("\nNumber of pbl session conducted: "))
  pbl_attended=int(input("\nNumber of pbl session attended: "))
  pbl_attendence=(pbl_attended/pbl_conducted)*50

  print("\nEnter appropriate marks according to the performance: ")
  print("\nFor Excellent/On time - 50 , Average/Late - 35 , Satisfactory/Very Late - 20 ")
  documentation=int(input("\nEnter a marks for documentation: "))
  participation=int(input("\nEnter a marks for participation in the group: "))
  implementation=int(input("\nEnter a marks for implementation: "))
  team_work=int(input("\nEnter a marks for team work: "))

  pbl_tw=(pbl_attendence+documentation+participation+implementation+team_work)/5

  print("\nTerm work for PBL: ",pbl_tw)

def cc():
  print("\n###### Code of Conduct #####")
  cc_conducted=int(input("\nNumber of cc session conducted: "))
  cc_attended=int(input("\nNumber of cc session attended: "))
  cc_attendence=(cc_attended/cc_conducted)*50

  print("\nEnter appropriate marks according to the performance: ")
  print("\nFor Excellent/On time - 50 , Average/Late - 35 , Satisfactory/Very Late - 20 ")
  reports=int(input("\nEnter a marks for report: "))
  participation=int(input("\nEnter a marks for participation in the activities: "))

  cc_tw=(cc_attendence+reports+participation)/3
  cc_tw=cc_tw/2

  print("\nTerm work for CC lab: ",cc_tw)

def main():
  print("\nTERM WORK CALCULATOR FOR AI & DS ENGINEERING SEM-IV")
  name=input("\nEnter student name: ")
  roll=input("\nEnter student roll no.: ")
  while True:
    print("\n*** MENU ***")
    print("\n1. Calculate TW for IOT lab")
    print("\n2. Calculate TW for DSA lab")
    print("\n3. Calculate TW for PBL lab")
    print("\n4. Calculate TW for CC lab")
    print("\n5. Exit")
    print("\nEnter Your Choice")
    choice=int(input())
    if choice==1:
      iotl() 
    elif choice==2:
      dsal()
    elif choice==3:
      pbl()
    elif choice==4:
      cc()
    elif choice==5:
      break
  
main()
