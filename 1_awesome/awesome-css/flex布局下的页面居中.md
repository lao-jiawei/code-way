当父盒子使用了flex元素，子盒子想要页面居中可以这样做

CSS

````css
.father{
  display:'flex';
  align-item:'center';
  justifyContent:'center';
}
.child{
  width:'50vw';
  height:'50vw';
}
````

HTML

````html
<div class='father'>
  <div class='child'>子盒子</div>
</div>
````

