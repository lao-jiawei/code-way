## Q：如何处理键盘遮挡input框？

* A：在input的点击事件，或者获取焦点的事件中，添加下面api即可

  ````jsx
  document.querySelector('#inputId').scrollIntoView();

