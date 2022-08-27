#include <Xm/Xm.h>
#include <Xm/PushB.h>
#include <stdio.h>

/* Prototype Callback function */

void pushed_fn(Widget, XtPointer, XmPushButtonCallbackStruct *);

int main(int argc, char **argv)
{
    XtAppContext  app;

    Widget top_wid = XtVaAppInitialize(&app, "Push", NULL, 0, &argc, argv, NULL, NULL);

    Widget button = XmCreatePushButton(top_wid, "Push_me", NULL, 0);

    /* tell Xt to manage button */
	XtManageChild(button);

	/* attach fn to widget */
    XtAddCallback(button, XmNactivateCallback, (XtCallbackProc)pushed_fn, NULL);

    XtRealizeWidget(top_wid); /* display widget hierarchy */
    XtAppMainLoop(app); /* enter processing loop */
}

void pushed_fn(Widget w, XtPointer client_data, XmPushButtonCallbackStruct *cbs)
{
	printf("Don't Push Me!!\n");
}

