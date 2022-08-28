
// 路径配置

require.config({
    paths: {
        echarts: './',
        theme: './theme'
        //与使用页面的相对路径，不是与这个js文件的相对路径
        //echarts文件夹中必须有chart文件夹，chart文件夹中有各个图形的js文件

        //echarts: 'http://echarts.baidu.com/build/dist'
    }

});
var theme = 'macarons';
       //可通过修改主题名称进行更换主题
var myChart = [];


var option1 = {
    tooltip: {
        formatter: "{a} <br/>{b} : {c}V"
    },
    toolbox: {
        show: false,
        feature: {
            mark: { show: true },
            restore: { show: true },
            saveAsImage: { show: true }
        }
    },
    series: [
                            {
                                //radius: [0, 100],
                                //center: [100, 100],
                                radius: [0 , '95%'],   //min(width, height) / 2 * 95%，[内半径，外半径] 
                                center: ['50%' , '50%'],   //min(width, height) * 50% 
                                min: 0,
                                max: 900,
                                name: '电压',
                                type: 'gauge',
                                detail: { formatter: '{value}V' },
                                data: [{ value: 0 , name: '总电压'}]
                            }
                           ]
};
var option2 = {
    tooltip: {
        formatter: "{a} <br/>{b} : {c}A"
    },
    toolbox: {
        show: false,
        feature: {
            mark: { show: true },
            restore: { show: true },
            saveAsImage: { show: true }
        }
    },
    series: [
                            {
                                //radius: [0, 100],
                                //center: [100, 100],
                                radius: [0 , '95%'],   //min(width, height) / 2 * 95%，[内半径，外半径] 
                                center: ['50%' , '50%'],   //min(width, height) * 50% 
                                min: -500,
                                max: 500,
                                name: '电流',
                                type: 'gauge',
                                detail: { formatter: '{value}A' },
                                data: [{ value: 0, name: '总电流'}]                                
                            }
                           ]
};


                        var option3 = {
                            tooltip: {
                                formatter: "{a} <br/>{b} : {c}%"
                            },
                            toolbox: {
                                show: false,
                                feature: {
                                    mark: { show: true },
                                    restore: { show: true },
                                    saveAsImage: { show: true }
                                }
                            },
                            series: [
                            {
                                //radius: [0, 100],
                                //center: [100, 100],
                                radius: [0 , '95%'],   //min(width, height) / 2 * 95%，[内半径，外半径] 
                                center: ['50%' , '50%'],   //min(width, height) * 50% 
                                min: 0,
                                max: 100,
                                name: 'SOC',
                                type: 'gauge',
                                detail: { formatter: '{value}%' },
                                data: [{ value: 0, name: 'SOC'}]                               
                            }
                           ]
                        };
                        var option4 = {
                            tooltip: {
                                formatter: "{a} <br/>{b} : {c}℃"
                            },
                            toolbox: {
                                show: false,
                                feature: {
                                    mark: { show: true },
                                    restore: { show: true },
                                    saveAsImage: { show: true }
                                }
                            },
                            series: [
                            {
                               // radius: [0, 100],
                               // center: [100, 100],
                               radius: [0 , '95%'],   //min(width, height) / 2 * 95%，[内半径，外半径] 
                                center: ['50%' , '50%'],   //min(width, height) * 50% 
                                min: -40,
                                max: 100,
                                name: '温度',
                                type: 'gauge',
                                detail: { formatter: '{value}℃' },
                                data: [{ value: 0, name: '温度'}]
                            }
                           ]
                        };

                        var option5 ={                           
                            tooltip: {
                                trigger: 'axis'
                            },
                            legend: {
                             orient : 'vertical',
                                x : 'left',
                                data: ['最高电压', '最低电压']
                            },
                            toolbox: {
                                show: false,
                                feature: {
                                    mark: { show: true },
                                    dataView: { show: true, readOnly: false },
                                    magicType: { show: true, type: ['line', 'bar'] },
                                    restore: { show: true },
                                    saveAsImage: { show: true }
                                }
                            },
                            calculable: true,
                            xAxis: [
        {
        data: [{value:'最大压差:0mV',
                        textStyle:{
                                                    fontSize: 14,
                                                    fontWeight: 'bolder',
                                                    color : 'red'
                                         }
                        }] 
        }
    ],
                            yAxis: [
        {
            type: 'value'
        }
    ],
                            series: [
        {
            name: '最高电压',
            type: 'bar',
            data: [0.0],
            markPoint: {
                data: [
                    { type: 'max', name: '最高电压' },
                ]
            },           
        },
        {
            name:'最低电压',
            type:'bar',
            data:[0.0],
            markPoint : {
                data : [
                    {type: 'min', name: '最低电压'},
                ]
            }            
        }
    ]
                        };  

    var option6 = {                                              
                            tooltip: {
                                trigger: 'axis'
                            },
                            legend: {
                             orient : 'vertical',
                                x : 'left',
                                data: ['最高温度', '最低温度']
                            },
                            toolbox: {
                                show: false,
                                feature: {
                                    mark: { show: true },
                                    dataView: { show: true, readOnly: false },
                                    magicType: { show: true, type: ['line', 'bar'] },
                                    restore: { show: true },
                                    saveAsImage: { show: true }
                                }
                            },
                            calculable: true,
                            xAxis: [
        {
            type: 'category',
            data: [{value:'最大温差:0℃',
                        textStyle:{
                                                    fontSize: 14,
                                                    fontWeight: 'bolder',
                                                    color : 'red'
                                         }
                        }]             
        }
    ],
                            yAxis: [
        {
            type: 'value'
        }
    ],
                            series: [
        {
            name: '最高温度',
            type: 'bar',
            data: [0],
            markPoint: {
                data: [
                    { type: 'max', name: '最高温度' },
                ]
            },           
        },
        {
            name:'最低温度',
            type:'bar',
            data:[0],
            markPoint : {
                data : [
                    {type: 'min', name: '最低温度'},
                ]
            }            
        }
    ]
                        };  

// 使用
require(
    [
        'echarts',
         'echarts/chart/gauge',
        'echarts/chart/bar',
        'echarts/chart/line',
        'echarts/chart/pie',
        'echarts/chart/treemap'
       
    // 使用柱状图就加载bar模块，按需加载
    ],

    function (ec) {
        // 基于准备好的dom，初始化echarts图表
        myChart[0] = ec.init(document.getElementById('Div1'), theme);
        myChart[0].setOption(option1);
        //生成第一个图表

        myChart[1] = ec.init(document.getElementById('Div2'), theme);
        myChart[1].setOption(option2);
        //生成第二个图表
        myChart[2] = ec.init(document.getElementById('Div3'), theme);
        myChart[2].setOption(option3);

         myChart[3] = ec.init(document.getElementById('Div4'), theme);
        myChart[3].setOption(option4);

         myChart[4] = ec.init(document.getElementById('Div5'), theme);
         myChart[4].setOption(option5);

         myChart[5] = ec.init(document.getElementById('Div6'), theme);
         myChart[5].setOption(option6);

        window.onresize = function () {
            myChart[0].resize && myChart[0].resize();
            myChart[1].resize && myChart[1].resize();
            myChart[2].resize && myChart[2].resize();
             myChart[3].resize && myChart[3].resize();
             myChart[4].resize && myChart[4].resize();
             myChart[5].resize && myChart[5].resize();
        }//自适应窗口
    }
);

    function callfromqtone(qtvalue) {

        option1 = {
            tooltip: {
                formatter: "{a} <br/>{b} : {c}V"
            },
            toolbox: {
                show: false,
                feature: {
                    mark: { show: true },
                    restore: { show: true },
                    saveAsImage: { show: true }
                }
            },
            series: [
                            {
                                //radius: [0, 100],
                                //center: [100, 100],
                                radius: [0 , '95%'],   //min(width, height) / 2 * 95%，[内半径，外半径] 
                                center: ['50%' , '50%'],   //min(width, height) * 50% 
                                min: 0,
                                max: 900,
                                name: '电压',
                                type: 'gauge',
                                detail: { formatter: '{value}V' },
                                data: [{ value: qtvalue, name: '总电压'}]
                            }
                           ]
        };
        myChart[0].setOption(option1);
    }
 function callfromqttwo(qtvalue) {
          option2 = {
              tooltip: {
                  formatter: "{a} <br/>{b} : {c}A"
              },
              toolbox: {
                  show: false,
                  feature: {
                      mark: { show: true },
                      restore: { show: true },
                      saveAsImage: { show: true }
                  }
              },
              series: [
                            {
                                //radius: [0, 100],
                                //center: [100, 100],
                                radius: [0 , '95%'],   //min(width, height) / 2 * 95%，[内半径，外半径] 
                                center: ['50%' , '50%'],   //min(width, height) * 50% 
                                min: -500,
                                max: 500,
                                name: '电流',
                                type: 'gauge',
                                detail: { formatter: '{value}A' },
                                data: [{ value: qtvalue, name: '总电流'}]

                            }
                           ]
          };             
                myChart[1].setOption(option2);
          }
          function callfromqtthree(qtvalue) {
          option3 = {
              tooltip: {
                  formatter: "{a} <br/>{b} : {c}%"
              },
              toolbox: {
                  show: false,
                  feature: {
                      mark: { show: true },
                      restore: { show: true },
                      saveAsImage: { show: true }
                  }
              },
              series: [
                            {
                                //radius: [0, 100],
                                //center: [100, 100],
                                radius: [0 , '95%'],   //min(width, height) / 2 * 95%，[内半径，外半径] 
                                center: ['50%' , '50%'],   //min(width, height) * 50% 
                                min: 0,
                                max: 100,
                                name: 'SOC',
                                type: 'gauge',
                                detail: { formatter: '{value}%' },
                                data: [{ value: qtvalue, name: 'SOC'}]
                            }
                           ]
                        };                        
                myChart[2].setOption(option3);
                        }
                        function callfromqtfour(qtvalue) {
          option4 = {
              tooltip: {
                  formatter: "{a} <br/>{b} : {c}℃"
              },
              toolbox: {
                  show: false,
                  feature: {
                      mark: { show: true },
                      restore: { show: true },
                      saveAsImage: { show: true }
                  }
              },
              series: [
                            {
                                //radius: [0, 100],
                                //center: [100, 100],
                                radius: [0 , '95%'],   //min(width, height) / 2 * 95%，[内半径，外半径] 
                                center: ['50%' , '50%'],   //min(width, height) * 50% 
                                min: -40,
                                max: 100,
                                name: '温度',
                                type: 'gauge',
                                detail: { formatter: '{value}℃' },
                                data: [{ value: qtvalue, name: '温度'}]
                            }
                           ]
                        };                        
                myChart[3].setOption(option4);
            }

                        function callfromqtfive(qthighvalue , qtlowvalue , qtcvalue , qtvhpos , qtvlpos) {
                        option5 = {            
                         title : {
                                text: qtvhpos,
                                x:'left',
                                y:'bottom',
                                textStyle:{
                                                    fontSize: 14,
                                                    fontWeight: 'bolder',
                                                    //color: '#333'
                                                    color : 'red'
                                                } 
                            },                      
                            tooltip: {
                                trigger: 'axis',
                            },
                            legend: {
                                orient : 'vertical',
                                x : 'left',
                                data: ['最高电压', '最低电压']
                            },
                            toolbox: {
                                show: false,
                                feature: {
                                    mark: { show: true },
                                    dataView: { show: true, readOnly: false },
                                    magicType: { show: true, type: ['line', 'bar'] },
                                    restore: { show: true },
                                    saveAsImage: { show: true }
                                }
                            },
                            calculable: true,
                            xAxis: [
        {
            type: 'category',           
             data: [{
                        value:qtcvalue,
                        textStyle:{
                                        fontSize: 14,
                                        fontWeight: 'bolder',
                                        color : 'red'
                                        }
                      }]
        }
    ],
                            yAxis: [
        {
            type: 'value'
        }
    ],
                            series: [
        {
            name: '最高电压',
            type: 'bar',
            data: [qthighvalue],
//            markPoint: {
//                data: [
//                    { type: 'max', name: '最高电压' },
//                ]
//            },           
        },
        {
            name:'最低电压',
            type:'bar',
            data:[qtlowvalue],
//            markPoint : {
//                data : [
//                    {type: 'min', name: '最低电压'},
//                ]
//            }            
        }
    ]
                        };              
                myChart[4].setOption(option5);
                        }
                        function callfromqtsix(qthtemvalue , qtltemvalue , qttvalue , qthpos , qtlpos) {
                        var option6 = {
                        title : {
                                text: qthpos,
                                x:'left',
                                y:'bottom',
                                textStyle:{
                                                    fontSize: 14,
                                                    fontWeight: 'bolder',
                                                    //color: '#333'
                                                    color : 'red'
                                                } 
                            },              
                            tooltip: {
                                trigger: 'axis'
                            },
                            legend: {
                                orient : 'vertical',
                                x : 'left',
                                data: ['最高温度', '最低温度']
                            },
                            toolbox: {
                                show: false,
                                feature: {
                                    mark: { show: true },
                                    dataView: { show: true, readOnly: false },
                                    magicType: { show: true, type: ['line', 'bar'] },
                                    restore: { show: true },
                                    saveAsImage: { show: true }
                                }
                            },
                            calculable: true,
                            xAxis: [
        {
            type: 'category',
            data: [{
                        value:qttvalue,
                        textStyle:{
                                        fontSize: 14,
                                        fontWeight: 'bolder',
                                        color : 'red'
                                        }
                      }]
        }
    ],
                            yAxis: [
        {
            type: 'value'
        }
    ],
                            series: [
        {
            name: '最高温度',
            type: 'bar',
            data: [qthtemvalue],
            markPoint: {
                data: [
                    { type: 'max', name: '最高温度' },
                ]
            },           
        },
        {
            name:'最低温度',
            type:'bar',
            data:[qtltemvalue],
            markPoint : {
                data : [
                    {type: 'min', name: '最低温度'},
                ]
            }            
        }
    ]
                        }; 
                myChart[5].setOption(option6);
                        }