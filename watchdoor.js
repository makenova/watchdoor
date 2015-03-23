// test with:
// curl -H "Authorization: Bearer cba4cf2b0adc42b8ea439ea4b9c61bb2035321d1" https://api.spark.io/v1/events/makenova

var EventSource = require('eventsource');

var accessToken = process.env.SPARK_TOKEN;
var deviceID = process.env.SPARK_DEVICE_ID;

var es = new EventSource("https://api.spark.io/v1/devices/" 
  + deviceID + "/events/?access_token=" + accessToken);

es.onmessage = function(e) {
  console.log(e.data);
};

es.onerror = function(e) {
  if (e.status === 401 || e.status === 403) {
    console.log('not authorized');
  }
  console.log('ERROR!');
};

es.on("makenova/doorState", function (e) {
  console.log(e.data);
}, false);
