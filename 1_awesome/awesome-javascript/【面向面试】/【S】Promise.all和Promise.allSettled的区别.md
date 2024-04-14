【返回结果不同】

* Promise.all==>返回每个promise的值

* Promise.allSettled===>返回由下列数据结构构成的结果

  | 键名   | 描述                           | 值                                            |
  | ------ | ------------------------------ | --------------------------------------------- |
  | status | 状态                           | fulfilled（成功）<br />rejected（失败）<br /> |
  | value  | 返回值（只有成功状态才会有）   |                                               |
  | reason | 错误原因（只有失败状态才会有） |                                               |

【处理出错动作不同】

* Promise.all ==>其中一个出错，会中断后续Promise
* Promise.allSettled==>其中一个出错，只会把状态写成rejected，后续Promise不会中断。

【抓取错误方法不同】

* Promise.all==>直接使用catch即可

  ````javascript
  Promise.all([...promiseArr]).then((r)=>{
    console.log(r);
  }).catch((e)=>{
    conselo.log(e);
  })
  ````

* Promise.allSettled==>需要对结果遍历

  ````javascript
  //类似Promise.all的处理方法;
  Promise.allSettled(promises).then((results) =>{
    for(const cur of results){
      if(cur.status==='rejected'){
        throw(cur?.reason)
      }
    }
  }).catch((e)=>{
   console.log('this is error',e); 
  });
  
  //单独处理
  const res=Promise.allSettled(promises).then((results) =>results);
  try{
    for(const cur of res){
      if(cur.status==='rejected'){
        throw(cur?.reason)
      }
    }
  }catch(e){
     console.log('this is error',e); 
  }
  ````

  