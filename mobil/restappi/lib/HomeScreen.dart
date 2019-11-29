import 'package:flutter/material.dart';


class HomeScreen extends StatelessWidget{
  @override
  Widget build(BuildContext context) {
    // TODO: implement build
    return Scaffold(
      body: Container(
        color: Color.fromARGB(255, 37, 42,57),
          child: Column(
            mainAxisAlignment: MainAxisAlignment.spaceAround,
            mainAxisSize: MainAxisSize.max,

            children: <Widget>[
              Padding(
                padding: const EdgeInsets.fromLTRB(8.0, 32.0, 8.0, 0.0),
                child: Container(

                  height: MediaQuery.of(context).size.height/2-50,
                  width: MediaQuery.of(context).size.width,
                  child: RaisedButton(
                    shape: RoundedRectangleBorder(borderRadius: new BorderRadius.circular(30.0)),


                    color: Colors.deepPurpleAccent,
                    child: Column(
                      children: <Widget>[
                        SizedBox(
                          height: 80,
                        ),
                        Text("GARSON",style: TextStyle(fontFamily: 'Raleway',fontSize: 75,color: Colors.white),textAlign: TextAlign.center,),
                        Icon(Icons.room_service,size: 100,),
                      ],
                    ),
                    onPressed: ()=>{},
                  ),
                ),
              ),
              Padding(
                padding: const EdgeInsets.fromLTRB(8.0, 0.0, 8.0, 20.0),
                child: Container(

                  height: MediaQuery.of(context).size.height/2-50,
                  width: MediaQuery.of(context).size.width,
                  child: RaisedButton(
                    shape: RoundedRectangleBorder(borderRadius: new BorderRadius.circular(30.0)),


                    color: Colors.deepOrangeAccent,
                    child: Column(
                      children: <Widget>[
                        SizedBox(
                          height: 80,
                        ),
                        Text("MUTFAK",style: TextStyle(fontFamily: 'Raleway',fontSize: 75,),textAlign: TextAlign.center,),
                        Icon(Icons.restaurant,size: 100,),
                      ],
                    ),
                    onPressed: ()=>{},
                  ),
                ),
              ),
            ],
          )
      ),
    );
  }
}