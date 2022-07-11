import pandas as pd
from datetime import datetime  
import binascii
from pyDes import des, CBC, PAD_PKCS5 


def des_encrypt(secret_key, s): #DES編碼
    iv = secret_key #DES金鑰
    k = des(secret_key, CBC, iv, pad=None, padmode=PAD_PKCS5)#建立DES跟選擇mode
    en = k.encrypt(s, padmode=PAD_PKCS5)#DES編碼
    return binascii.b2a_hex(en)#回傳DES編碼

def des_decrypt(secret_key, s):#DES解碼
    iv = secret_key #DES金鑰
    k = des(secret_key, CBC, iv, pad=None, padmode=PAD_PKCS5)#建立DES跟選擇mode
    de = k.decrypt(binascii.a2b_hex(s), padmode=PAD_PKCS5)#DES解碼
    return de#回傳DES解碼
def so(location,df):#bytes跟str轉換
    passwordt1=df.loc[location,'密碼'].strip('b')#跟資料庫要密碼
    passwordt1=passwordt1.strip('\'')
    passwordt1=bytes(passwordt1, encoding = "utf8")
    passwordt = des_decrypt(key, passwordt1)#密碼做解碼
    passwordt=str(passwordt, encoding = "utf8")
    passwordt=passwordt.strip('b')
    passwordt=passwordt.strip('\'')  
    return passwordt
def changepassword(location,df): #一個月未改密碼所以要求更改密碼
            print ('密碼超過一個月未改,需更換密碼') 
            password=input('請輸入舊密碼 ');  
            passwordt=so(location,df)#密碼做解碼  
            while (str(passwordt)!=str(password)):#判斷舊密碼是否成功
                print ('密碼錯誤')
                password=input('請輸入舊密碼 ');   
            password=input('請輸入新密碼 '); 
            while (str(passwordt)==str(password)):#判新密碼是否與舊密碼一樣
                print ('密碼錯誤請與上次密碼不相同')
                password=input('請輸入新密碼 ');    
            a=0
            b=0
            c=0
            d=0
            for i in password:
               if i.isupper():#判新密碼是否有大寫英文
                 a=1
               if i.islower():#判新密碼是否有小寫英文
                 b=1
               if i.isdigit():#判新密碼是否有數字
                 c=1       
            if len(password)>7:#判新密碼長度>=8
              d=1    
            while a+b+c+d!=4:
              print ('密碼至少8個字元需包含數字與大、小寫')     
              password=input('請重新輸入密碼 ');  
              a=0
              b=0
              c=0
              d=0
              for i in password:
                if i.isupper():
                  a=1
                if i.islower():
                  b=1
                if i.isdigit():
                  c=1         
              if len(password)>7:
                  d=1 
            password2=input('請再次輸入新密碼 ');       
            while (str(password)!=str(password2)):
                 print ('密碼錯誤') 
                 password2=input('請再次輸入新密碼 ');
            password = des_encrypt(key, password)              
            df.loc[location,'密碼']=password;  #更改密碼
            df.loc[location,'密碼時間']=time;   #更改密碼時間
            writer2 = pd.ExcelWriter('logindatabase.xlsx')
            df.to_excel(writer2)
            writer2.save()#修改資料
            print ('請重新登錄')  
            login()
def login():   
    df = pd.read_excel("logindatabase.xlsx",usecols=["帳號","密碼","登入日期",'在線情況','密碼時間'])#讀取excl的資料庫檔案   
    username=input('請輸入帳號 ');
    password=input('請輸入密碼 '); 
    bo= df['帳號'].isin([username]);#判斷帳號是否有存在
    location=-1
    a=0
    b=0
    e=0
    for i in range (0,bo.shape[0]):#判斷帳號是否有存在
           if bo[i]==True:
             location=i;#抓取帳號位置
             break
    if location==-1:#抓取帳號位置是否成功
        a=1
    else:
        passwordt=so(location,df)#以抓到的帳號位置的密碼做解碼 
        if (str(passwordt)!=str(password)):#判斷密碼是否一樣
            b=1        
    while (a==1 or b ==1):#'帳號密碼錯誤,重新輸入
        if(e>1):#判斷錯誤次數不超過3次
            exit()
        e+=1
        print ('帳號密碼錯誤,請重新輸入')
        username=input('請輸入帳號 ');
        password=input('請輸入密碼 '); 
        bo= df['帳號'].isin([username]);
        location=-1
        a=0
        b=0
        for i in range (0,bo.shape[0]):
           if bo[i]==True:
             location=i;
             break
        if location==-1:
         a=1
        else:
          passwordt=so(location,df)
          if (str(passwordt)!=str(password)):
            b=1
    if (a==0 and b==0):#登入成功
        print ('登入成功 上次登入時間:'+str(df.loc[location,'登入日期']))
        if time.month*31+time.day-df.loc[location,'密碼時間'].month*31-df.loc[location,'密碼時間'].day > 30: #判斷密碼修改時間是否超過1個禮拜
            changepassword(location,df)
        df.loc[location,'登入日期']=time;#修改登入日期
        df.loc[location,'在線情況']+=1;#修改在線情況
        writer2 = pd.ExcelWriter('logindatabase.xlsx')
        df.to_excel(writer2)
        writer2.save()#上傳修改資料
        if df.loc[location,'在線情況']>1:#判斷在線情況，做警示
            print('第'+str(df.loc[location,'在線情況'])+'次登入') 
        while True:
          out=input('登出請輸入out ') #登出
          if (out == 'out'):    
            df.loc[location,'在線情況']-=1;#登出，修改在線情況
            writer2 = pd.ExcelWriter('logindatabase.xlsx')
            df.to_excel(writer2)
            writer2.save()#上傳修改資料
            print('登出')
            exit()#結束程式
def registered():#註冊
    re=0 #判斷帳號重複旗子
    username=input('請輸入帳號 ');
    df = pd.read_excel("logindatabase.xlsx",usecols=["帳號","密碼","登入日期",'在線情況','密碼時間'])
    account=df['帳號'].astype('string')#修改資料型態
    bo= df['帳號'].isin([username]);#判斷帳號重複
    for i in range (0,bo.shape[0]):
        if bo[i]==True:
           re=1;
           break
    while(re==1):
        print ('帳號重複(已有人使用)')
        username=input('請重新輸入帳號 '); 
        bo= df['帳號'].isin([username]);
        for i in range (0,bo.shape[0]):
           if bo[i]==True:
             re=1;
             break
           else:
             re=0;
    password=input('請輸入密碼 ');         
    a=0
    b=0
    c=0
    d=0
    for i in password:
        if i.isupper():
            a=1
        if i.islower():
            b=1
        if i.isdigit():
            c=1       
    if len(password)>7:
        d=1    
    while a+b+c+d!=4:
        print ('密碼至少8個字元需包含數字與大、小寫')     
        password=input('請重新輸入密碼 ');  
        a=0
        b=0
        c=0
        d=0
        for i in password:
          if i.isupper():
            a=1
          if i.islower():
            b=1
          if i.isdigit():
            c=1         
        if len(password)>7:
            d=1   
    password = des_encrypt(key, password) #密碼做編碼        
    df1 = pd.DataFrame({'帳號':[username],'密碼':[password],'登入日期':[time],'在線情況':[0],'密碼時間':[time]})
    
    df=df.append(df1,ignore_index=True)#新增一筆帳號的資料     
    writer = pd.ExcelWriter('logindatabase.xlsx')
    df.to_excel(writer)
    writer.save()#上傳資料
    print('註冊成功')  

def ask():
    while True:
     fg =input('選擇註冊或登入,登入請輸入1,註冊請輸入0\n');  
     if fg=='0':
        registered()
     elif fg=='1': 
        login()

key='88888888'
time=datetime.now()
ask()
