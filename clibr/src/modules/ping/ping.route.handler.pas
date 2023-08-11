unit ping.route.handler;

interface

uses
  Horse,
  dmfbr.modular,
  Ping.controller,
  dmfbr.route.handler.horse;

type
  TPingRouteHandler = class(TRouteHandlerHorse)
  protected
    procedure RegisterRoutes; override;
  public
    procedure Ping(Req: THorseRequest; Res: THorseResponse);
  end;

implementation

{ TPingRouteHandler }

procedure TPingRouteHandler.RegisterRoutes;
begin
  RouteGet('/ping', Ping);
end;

procedure TPingRouteHandler.Ping(Req: THorseRequest; Res: THorseResponse);
var
  LResult: string;
begin
  LResult := Modular.Get<TPingController>.Ping;
  Res.Send(LResult).Status(200);
end;

end.