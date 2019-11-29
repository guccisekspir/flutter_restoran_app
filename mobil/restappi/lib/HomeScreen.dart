import 'package:flare_flutter/flare.dart';
import 'package:flare_flutter/flare_actor.dart';
import 'package:flare_flutter/flare_render_box.dart';
import 'package:flutter/material.dart';
import 'package:flare_dart/actor.dart';
import 'package:restappi/main.dart';


class HomeScreen extends StatelessWidget{
  @override
  Widget build(BuildContext context) {
    // TODO: implement build
    return Scaffold(
      body: Container(
        color: renkArka,
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


                    color: renkGarsonYesil,
                    child: Column(
                      children: <Widget>[
                        SizedBox(
                          height: 50,
                        ),
                        Text("GARSON",style: TextStyle(fontFamily: 'Raleway',fontSize: 75,color: Colors.white),textAlign: TextAlign.center,),
                        SizedBox(
                            width: 150,
                            height: 150,
                            child: FlareActor("assets/garson.flr",sizeFromArtboard: true,animation: "Untitled",fit:BoxFit.fill)),

                      ],
                    ),
                    onPressed: ()=>{
                      Navigator.pushNamed(context, '/tableScreen')
                      },
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


                    color: renkMutfakSari,
                    child: Column(
                      children: <Widget>[
                        SizedBox(
                          height: 50,
                        ),
                        Text("MUTFAK",style: TextStyle(fontFamily: 'Raleway',fontSize: 75,color: Colors.white),textAlign: TextAlign.center,),
                        SizedBox(
                          width: 270,
                            height: 150,
                            child: FlareActor("assets/mutfakk.flr",sizeFromArtboard: true,animation: "Yumy",fit: BoxFit.fill,)),
                      ],
                    ),
                    onPressed: ()=>{
                      Navigator.pushNamed(context, '/kitchenScreen')
                    },
                  ),
                ),
              ),
            ],
          )
      ),
    );
  }


}