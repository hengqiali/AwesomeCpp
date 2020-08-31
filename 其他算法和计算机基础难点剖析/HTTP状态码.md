100 Continue        
这个临时响应表明，迄今为止的所有内容都是可行的，客户端应该继续请求，如果已经完成，则忽略它             

200 OK     
请求成功。成功的含义取决于HTTP方法：
   - GET：资源已被提取并在消息正文中传输
   - HEAD：实体标头位于消息正文中
   - POST：描述动作结果的资源在消息体中传输
   - TRACE：消息正文包含服务器收到的请求消息
 
301 Move Permantently               
资源被转移了，请求将被重定向

302 Found          
通知客户端资源在其他地方被找到了，但需要使用GET方法来获得它

304 Not Modified        
申请的资源没有更新，和之前获得的相同

400 Bad Request    
  - 语义有误，当前请求无法被服务器理解。除非进行修改，否则客户端不应该重复提交这个请求
  - 请求参数有误

401 Unauthorized
当前请求需要用户认证

403 Forbidden         
访问被服务器禁止，通常是因为客户端没有权限访问该资源

404 Not Found     
资源没找到

500 Internel Servel Error           
服务器遇到了不知道如何处理的情况

503 Server Unavailable
暂时无法访问服务器 常见原因是服务器因维护或重载而停机


[更多状态码和状态信息详见此处](https://developer.mozilla.org/zh-CN/docs/Web/HTTP/Status)
