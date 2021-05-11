y = y2globalcbde;
plot(y)
% 291559
% 0.00153612 0.420097 1.09948 1.69962 2.57388 2.80113 3.56686 3.95096 4.61098 4
hold on

% yo1 = 291559;
% yo2 = 2241.52;
% yo3 = 0.0392793;
% yo4 = 2.96626e+08;
yo1bde = 294336;
yo2bde = 1861.01;
ystandard = yo2bde;
plot([0 10000],[ystandard ystandard])
legend('全空间','最优值')
% hold on
% plot([0 10000],[ymean ymean])
maxp = (max(y)-ystandard)/ystandard;
minp = (min(y)-ystandard)/ystandard;
