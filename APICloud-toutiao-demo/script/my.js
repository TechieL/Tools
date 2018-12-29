//返回id，请在项目概览中查看id:
function MyfnGetAppId() {
    return "A60621927812355";
}
//返回原始key，请在项目概览中查看appKey:
function MyfnGetSourceAppKey() {
  //范例："731219C9-57DE-8974-D599-4362EC6E7746"
  return "731219C9-57DE-8974-D599-4362EC6E7746";
}
//返回经过sha1计算完成后的appkey,不需要修改
function MyfnGetAppKey() {
    var now = Date.now();
    var appKey = SHA1(MyfnGetAppId() + "UZ" +
        MyfnGetSourceAppKey() +
        "UZ" + now) + "." + now;
    return appKey;
}
