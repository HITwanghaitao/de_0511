% 适应度绘图
y1 = f1fitness;
y2 = f2fitness;
y3 = f3fitness;
subplot(331)
plot(y1(:,1))
title('f1最佳适应度')
subplot(334)
plot(y1(:,2))
title('F1最佳适应度')
subplot(337)
plot(y1(:,3))
title('约束函数值')

subplot(332)
plot(y2(:,1))
title('f2最佳适应度')
subplot(335)
plot(y2(:,2))
title('F2最佳适应度')
subplot(338)
plot(y2(:,3))
title('约束函数值')

subplot(333)
plot(y3(:,1))
title('f3最佳适应度')
subplot(336)
plot(y3(:,2))
title('F3最佳适应度')
subplot(339)
plot(y3(:,3))
title('约束函数值')