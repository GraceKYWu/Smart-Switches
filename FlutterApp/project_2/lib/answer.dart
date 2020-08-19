import 'package:flutter/material.dart';
import 'package:http/http.dart';

/*class Answer extends StatelessWidget{
  String place;
  String path;
  String ip = 'http://192.168.31.143';

  Answer(this.place, this.path);

  //List<bool>

  @override 
  Widget build(BuildContext context){
    return Container(
      width: double.infinity,
      child: RaisedButton(
        color: Colors.yellow[200],
        child: Text(place, 
            style: TextStyle(color: Colors.yellow[800]),),
        
        onPressed: () async { 
          
          Response response = await get(ip+path);
          print(response.statusCode); 
        },
        ),
    );
  }
}
*/

class Answer extends StatefulWidget{
  
  final String place;
  final String path;
  final String ip = 'http://192.168.31.143';

  final bool val;
  final Future<void> Function(String, String, String) onclick;

  const Answer({Key key, this.place, this.path, this.val, this.onclick}) : super(key: key);


  @override
  _AnswerState createState() => new _AnswerState();
}

class _AnswerState extends State<Answer>{
  @override 
  Widget build(BuildContext context){
    return AnimatedContainer(
      duration: Duration(milliseconds: 1000),
      height: 40.0,
      width: 100.0,
      decoration: BoxDecoration(
        borderRadius: BorderRadius.circular(20.0),
        color: widget.val ? Colors.greenAccent[100]: Colors.redAccent[100].withOpacity(0.5)
      ),
      child: Stack(
        children: <Widget>[
          AnimatedPositioned(
            duration: Duration(milliseconds: 1000),
            curve: Curves.easeIn,
            top: 3.0,
            left: widget.val ? 60.0 : 0.0,
            right: widget.val ? 0.0 : 60.0,
            child: InkWell(
              onTap: () => { widget.onclick(widget.ip, widget.path, widget.place) },
              child: AnimatedSwitcher(
                duration: Duration(milliseconds: 500),
                transitionBuilder: (Widget child, Animation<double> animation){
                  return RotationTransition(
                    child: child, turns: animation
                    );
                },
                child: widget.val ? Icon(Icons.check_circle, color: Colors.green, size: 35.0,
                key: UniqueKey(),
                ) : Icon(Icons.remove_circle_outline, color: Colors.red, size: 35.0,
                key: UniqueKey(),
                )
                ),
            ),
            )
        ],
      )

      );
  }
}

