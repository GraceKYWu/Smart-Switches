import 'package:flutter/material.dart';
import './answer.dart';
import 'package:http/http.dart';

class insideColumn extends StatefulWidget {

  @override
  _insideColumnState createState() => _insideColumnState();
}

class _insideColumnState extends State<insideColumn> {
  bool living_room = false;
  bool kitchen = false;
  bool both = false;

  String ip = 'http://192.168.31.143';

  @override
  Widget build(BuildContext context) {
    return Column(
      children: [
        SizedBox(height: 100),
        Text('Living Room Light'),
        SizedBox(height: 20),
        Answer(
            place: 'Living Room On',
            path: '/livroom/',
            val: living_room,
            onclick: (ip, path, place) async {
              this.setState(() {
                living_room = !living_room;

                if (kitchen && living_room) {
                  both = true;
                } else {
                  both = false;
                }
              });

              if (living_room) {
                Response response = await get(ip + path + '1');
                print(response.statusCode);
              } else {
                Response response = await get(ip + path + '0');
                print(response.statusCode);
              }
            }),
        SizedBox(height: 20),
        Text('Kitchen Light'),
        SizedBox(height: 20),
        Answer(
          place: 'Kitchen On',
          path: '/kitchen/',
          val: kitchen,
          onclick: (ip, path, place) async {
            this.setState(() {
              kitchen = !kitchen;
              if (kitchen && living_room) {
                both = true;
              } else {
                both = false;
              }
            });
          if (kitchen) {
                Response response = await get(ip + path + '1');
                print(response.statusCode);
              } else {
                Response response = await get(ip + path + '0');
                print(response.statusCode);
              }
          
          },
        ),
        SizedBox(height: 20),
        Text('Both Lights'),
        SizedBox(height: 20),
        Answer(
            place: 'Both On',
            path: '/both/',
            val: both,
            onclick: (ip, path, place) async {
              this.setState(() {
                both = !both;
                if (both) {
                  kitchen = true;
                  living_room = true;
                } else {
                  kitchen = false;
                  living_room = false;
                }
              });

              if (both) {
                Response response = await get(ip + path + '1');
                print(response.statusCode);
              } else {
                Response response = await get(ip + path + '0');
                print(response.statusCode);
              }
            }),
      ],
    );
  }
}

/*toggleButtonState (){
  setState((){
     
  });
}*/
